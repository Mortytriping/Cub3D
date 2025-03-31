/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:58:00 by abaroukh          #+#    #+#             */
/*   Updated: 2025/03/31 11:58:01 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_inside(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
					return (err_msg("Map not conform!"), false);
				if ((map[i - 1] && (map[i - 1][j] == ' '
						|| map[i - 1][j] == '\n' || map[i - 1][j] == '\0'))
						|| (map[i + 1] && (map[i + 1][j] == ' ' ||
						map[i + 1][j] == '\n' || map[i + 1][j] == '\0')) ||
						(map[i][j - 1] == ' ' || map[i][j - 1] == '\n'
						|| map[i][j - 1] == '\0') ||
						(map[i][j + 1] == ' ' || map[i][j + 1] == '\n'
						|| map[i][j + 1] == '\0'))
					return (err_msg("Map not conform!"), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_borders(char **map, t_cub *data, int i, int j)
{
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
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (i == 0 || i == data->map->height - 1)
					return (err_msg("Map not closed!"), false);
				if (j == 0 || j == data->map->width - 1)
					return (err_msg("Map not closed!"), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
