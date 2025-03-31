/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex_colors_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:58:09 by abaroukh          #+#    #+#             */
/*   Updated: 2025/03/31 11:58:10 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	handle_texture(char **line_tab, char *clean_path, t_map *map, int *seen)
{
	if (ft_strncmp(line_tab[0], "NO", 2) == 0 && ++seen[0] == 1)
		return (init_textures(line_tab[0], clean_path, map));
	if (ft_strncmp(line_tab[0], "SO", 2) == 0 && ++seen[1] == 1)
		return (init_textures(line_tab[0], clean_path, map));
	if (ft_strncmp(line_tab[0], "WE", 2) == 0 && ++seen[2] == 1)
		return (init_textures(line_tab[0], clean_path, map));
	if (ft_strncmp(line_tab[0], "EA", 2) == 0 && ++seen[3] == 1)
		return (init_textures(line_tab[0], clean_path, map));
	if (ft_strncmp(line_tab[0], "F", 1) == 0 && ++seen[4] == 1)
		return (init_colors(line_tab[0], clean_path, map));
	if (ft_strncmp(line_tab[0], "C", 1) == 0 && ++seen[5] == 1)
		return (init_colors(line_tab[0], clean_path, map));
	return (false);
}

bool	parse_line(char *line, int fd, t_map *map, int *seen)
{
	char	**line_tab;
	char	*clean_path;
	bool	success;

	line_tab = ft_split_sp1(line);
	free(line);
	if (!line_tab)
		return (wait_gnl(fd), err_msg("Memory issue!"), false);
	if (!line_tab[0] || !line_tab[1])
		return (free_array(line_tab),
			err_msg("Incomplete texture/color!"), false);
	clean_path = ft_strtrim(line_tab[1], " \t\n\r");
	if (!clean_path)
		return (free_array(line_tab), err_msg("Memory issue!"), false);
	success = handle_texture(line_tab, clean_path, map, seen);
	free(clean_path);
	free_array(line_tab);
	if (!success)
		return (err_msg("Invalid or duplicate texture/color!"), false);
	return (true);
}
