#include "../../includes/cub3d.h"

// bool	check_inside(char **map)
// {
// 	return (true);
// }

bool	check_player(char **map, t_cub *data, int player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				player++;
				data->p1->py = j;
				data->p1->px = i;
				data->p1->orientation = map[i][j];
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (false);
	return (true);
}

bool	valid_map(char **huge_tab, t_map *map, t_cub *data)
{
	map->map = cpy_map(huge_tab, map);
	if (!map->map)
		return (false);
	// if (!check_borders(map->map))
	// 	return (false);
	// if (!check_inside(map->map))
	// 	return (false);
	if (!check_player(map->map, data, 0))
		return (false);
	return (true);
}
