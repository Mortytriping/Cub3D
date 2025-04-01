/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:58:17 by abaroukh          #+#    #+#             */
/*   Updated: 2025/04/01 11:05:04 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map_null(t_map *map)
{
	map->tex_no = NULL;
	map->tex_so = NULL;
	map->tex_we = NULL;
	map->tex_ea = NULL;
}

bool	parsing(char **av, int ac, t_cub *data)
{
	int		raw_map;
	int		i;

	i = 0;
	if (!av || ac != 2)
		return (err_msg("Too few or too much arguments (expected 2)!"), false);
	while (av[1][i])
		i++;
	if (i >= 4 && ft_strncmp(av[1] + i - 4, ".cub", 4) == 0)
		;
	else
		return (err_msg("Map file must have .cub extension!"), false);
	raw_map = open(av[1], O_RDONLY);
	if (raw_map < 0)
		return (err_msg("Can't open map file check path and permissions!"),
			false);
	init_map_null(data->map);
	if (!dispatch_textures_colors(raw_map, data->map, 0))
		return (free_textures(data->map), close(raw_map), false);
	if (!init_map(raw_map, data->map, data))
		return (free_textures(data->map), close(raw_map), false);
	close (raw_map);
	return (true);
}
