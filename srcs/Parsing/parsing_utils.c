#include "../../includes/cub3d.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_parse(char const *s1, char const *set, int i)
{
	char	*new_str;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	while (s1[i] && (is_set(s1[i], set)))
		i++;
	start = i;
	i = ft_strlen(s1);
	while (i > 0 && (is_set(s1[i - 1], set)))
		i--;
	end = i;
	if (start >= end)
		return (free((char *)s1), ft_strdup(""));
	new_str = malloc(sizeof(char) * (end - start + 1));
	if (!new_str)
		return (free((char *)s1), NULL);
	i = 0;
	while (start < end)
		new_str[i++] = s1[start++];
	new_str[i] = '\0';
	free((char *)s1);
	return (new_str);
}
