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
			if (map[i][j] == '0')
			{
				if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
					return (false);
				if ((i > 0 && map[i - 1][j] == ' ') ||
					(map[i + 1] && map[i + 1][j] == ' ') ||
					(j > 0 && map[i][j - 1] == ' ') ||
					(map[i][j + 1] && map[i][j + 1] == ' '))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_top_bottom(char **map, t_cub *data)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			return (false);
		j++;
	}
	j = 0;
	while (map[data->map->height - 1][j])
	{
		if (map[data->map->height - 1][j] != '1'
			&& map[data->map->height - 1][j] != ' ')
			return (false);
		j++;
	}
	return (true);
}

bool	check_sides(char **map, t_cub *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		if ((int)ft_strlen(map[i]) < data->map->width)
			return (false);
		if (map[i][0] != '1' && map[i][0] != ' ')
			return (false);
		if (map[i][data->map->width - 1] != '1'
			&& map[i][data->map->width - 1] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	check_borders(char **map, t_cub *data)
{
	if (!check_top_bottom(map, data))
		return (false);
	if (!check_sides(map, data))
		return (false);
	return (true);
}
