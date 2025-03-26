#include "../../includes/cub3d.h"

bool	check_inside(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' ||
				map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (i == 0 || !map[i + 1] || j == 0)
					return (false);
				if ((map[i - 1][j] == ' ') ||
					(map[i + 1][j] == ' ') ||
					(map[i][j - 1] == ' ') ||
					(map[i][j + 1] == ' '))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_borders(char **map, t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (map[i] && map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W')
			{
				j++;
				continue ;
			}
			if (map[i][j] == '0'
				|| map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (i == 0 || i == data->map->height - 1)
					return (false);
				if (j == 0 || j == data->map->width - 1)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
