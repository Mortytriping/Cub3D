/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:40:58 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/17 16:34:54 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// input = ./cub3d ARG_FD

// 2 blocks :

// - Directions texture (NO/SO/WE/EA)&& FLOOR COLOR (F) + SKY COLOR (C)
	// can be on a single line as on multiple line (with spaces)
// - MAP (1 = WALL, 0 = CAN NAVIGATE, N S W E = spawn looking in direction)
	// all borders should be 1
	// inside the 1, only 0 and one time the camera with the direction
	// outside of the 1, spaces are ok
	// a 0 is strictly bordered by either 0 or 1 or spawn, no spaces
	// same for the spawn, only 0 or 1

bool	init_textures_colors(int fd, t_map *map)
{
	char	*line;
	char	**line_tab;
	int		i;
	int		j;
	char	*texture;

	while (i < 6)
	{
		while (1)
		{
			j = 0;
			line = get_next_line(fd);
			if (!line)
				return (false);
			line_tab = ft_split(line, " ");
			if (!line_tab)
				return (free(line), false);
			if (strncmp(line[j], "NO", 2) || strncmp(line[j], "SO", 2)
				|| strncmp(line[j], "WE", 2) || strncmp(line[j], "EA", 2)
				|| strncmp(line[j], "F", 1) || strncmp(line[j], "C", 1))
			{
				i++;
			}
			free(line_tab);
			free(line);
			if (i == 5)
				break ;
		}
	}
	return (true);
}

bool	parsing(char **av, int ac, t_map map)
{
	int	raw_map;
	int	i;

	i = 0;
	if (!av || ac != 2)
		return (ft_putstr_fd("Error on arguments!\n", 2), false);
	while (av[1][i])
		i++;
	if (i >= 3 && av[1][i] == "b" && av[1][i - 1] == "u"
			&& av[1][i - 2] == "c" && av[1][i - 3] == ".")
		;
	else
		return (ft_putstr_fd("Error map is not \".cub\"!\n", 2), false);
	raw_map = open(av[1], O_RDONLY);
	if (raw_map < 0)
		return (ft_putstr_fd("Error can't open the map!\n", 2), false);
	if (!init_textures_colors(raw_map, &map))
		return (ft_putstr_fd("Error on textures initialization!\n", 2), false);
	if (!init_map(raw_map, &map))
		return (ft_putstr_fd("Error on map initialization!\n", 2), false);
	close (raw_map);
	return (true);
}
