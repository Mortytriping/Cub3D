#include "../../includes/cub3d.h"

long	ft_atol(const char *nptr)
{
	long	nb;
	long	sign;

	nb = 0;
	sign = 1;
	while ((*nptr && *nptr == ' ') || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		nb = nb * 10 + *nptr - '0';
		nptr++;
	}
	return (nb * sign);
}

char	**ft_split_sp1(char *str)
{
	char	**result;
	int		i;
	int		start;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == ' ')
		i++;
	start = i;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	result = (char **)malloc(sizeof(char *) * 3);
	if (!result)
		return (NULL);
	result[0] = ft_substr(str, start, i - start);
	if (!result[0])
		return (free(result), NULL);
	result[1] = ft_strdup(&str[i]);
	if (!result[1])
		return (free(result[0]), free(result), NULL);
	result[2] = NULL;
	return (result);
}

bool	valid_path(char *texture)
{
	int		i;
	int		fd;
	char	*line;

	i = ft_strlen(texture);
	if (i >= 4 && ft_strncmp(texture + i - 4, ".cub", 4) == 0)
		;
	else
		return (err_msg("Texture is not a \".xpm\" file!"), false);
	fd = open(texture, O_RDONLY);
	if (fd < 0)
		return (err_msg("Can't open the texture!"), false);
	line = get_next_line(fd);
	if (line[0] == '\0')
		return (err_msg("Texture file is empty!"), false);
	close (fd);
	return (true);
}
