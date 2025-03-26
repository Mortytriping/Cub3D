#include "../../includes/cub3d.h"

char	**cpy_map(char **huge_tab, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (huge_tab[i])
		i++;
	map->map = malloc(sizeof(char *) * (i + 1));
	if (!map->map)
		return (free_array(huge_tab), NULL);
	while (j < i)
	{
		map->map[j] = ft_strdup(huge_tab[j]);
		j++;
	}
	map->map[j] = NULL;
	return (map->map);
}

bool	init_map(int fd, t_map *map, t_cub *data)
{
	char	*line;
	char	**huge_very_huge_tab;
	int		x;
	bool	map_started;

	huge_very_huge_tab = malloc(sizeof(char *) * 10000);
	if (!huge_very_huge_tab)
		return (false);
	x = 0;
	map_started = false;
	line = get_next_line(fd);
	while (line && (line[0] == '\n' || check_empty_line(line)))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (free_array(huge_very_huge_tab), false);
	while (line != NULL)
	{
		if (line[0] == '\n' || check_empty_line(line))
		{
			free(line);
			free_array(huge_very_huge_tab);
			return (err_msg("Empty line within map is not allowed!"), false);
		}
		huge_very_huge_tab[x] = ft_strdup(line);
		if (!huge_very_huge_tab[x])
			return (free(line), free_array(huge_very_huge_tab), false);
		x++;
		free(line);
		line = get_next_line(fd);
	}
	huge_very_huge_tab[x] = NULL;
	if (!valid_map(huge_very_huge_tab, map, data))
		return (free_array(huge_very_huge_tab), false);
	return (free_array(huge_very_huge_tab), true);
}
