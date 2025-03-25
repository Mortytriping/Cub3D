#include "../../includes/cub3d.h"

void	p1_position(t_cub *data)
{
	if (data->p1->orientation == 'N')
		data->p1->pov = NO;
	if (data->p1->orientation == 'S')
		data->p1->pov = SU;
	if (data->p1->orientation == 'E')
		data->p1->pov = EA;
	if (data->p1->orientation == 'W')
		data->p1->pov = WE;
}

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
				data->p1->py = i * SCALE_BLOCK + (SCALE_BLOCK / 2);
				data->p1->px = j * SCALE_BLOCK + (SCALE_BLOCK / 2);
				data->p1->orientation = map[i][j];
				p1_position(data);
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (false);
	return (true);
}

void	find_maxs(t_map *map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	width = 0;
	height = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (j >= width)
				width = j;
			j++;
		}
		i++;
	}
	height = i;
	map->height = height;
	map->width = width;
}

bool	valid_map(char **huge_tab, t_map *map, t_cub *data)
{
	map->map = cpy_map(huge_tab, map);
	if (!map->map)
		return (false);
	find_maxs(map);
	if (!check_borders(map->map, data))
		return (false);
	if (!check_inside(map->map))
		return (false);
	if (!check_player(map->map, data, 0))
		return (false);
	return (true);
}
