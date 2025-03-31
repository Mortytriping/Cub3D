/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:58:12 by abaroukh          #+#    #+#             */
/*   Updated: 2025/03/31 11:58:13 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	assign_colors(char **colors, t_map *map, int type)
{
	if (type == 1)
	{
		map->floor->t = 0;
		map->floor->r = ft_atol(colors[0]);
		map->floor->g = ft_atol(colors[1]);
		map->floor->b = ft_atol(colors[2]);
		map->floor->color = create_trgb(map->floor->t, map->floor->r,
				map->floor->g, map->floor->b);
	}
	else if (type == 2)
	{
		map->floor->t = 0;
		map->floor->r = ft_atol(colors[0]);
		map->floor->g = ft_atol(colors[1]);
		map->floor->b = ft_atol(colors[2]);
		map->floor->color = create_trgb(map->floor->t, map->floor->r,
				map->floor->g, map->floor->b);
	}
}

bool	init_colors(char *f_or_c, char *color, t_map *map)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_split(color, ',');
	if (!colors)
		return (err_msg("Color init!"), false);
	while (colors[i])
	{
		if (ft_strlen(colors[i]) > 11)
			return (free_array(colors), err_msg("Color init!"), false);
		i++;
	}
	if (i != 3)
		return (free_array(colors), err_msg("Color init!"), false);
	if (ft_strncmp(f_or_c, "F", 1) == 0)
		assign_colors(colors, map, 1);
	else if (ft_strncmp(f_or_c, "C", 1) == 0)
		assign_colors(colors, map, 2);
	if (ft_atol(colors[0]) > INT_MAX || ft_atol(colors[0]) < INT_MIN
		|| ft_atol(colors[1]) > INT_MAX || ft_atol(colors[1]) < INT_MIN
		|| ft_atol(colors[2]) > INT_MAX || ft_atol(colors[2]) < INT_MIN)
		return (free_array(colors), err_msg("Color init!"), false);
	return (free_array(colors), true);
}

bool	init_textures(char *tex_orientation, char *tex_path, t_map *map)
{
	char	**target;

	if (!tex_path || !valid_path(tex_path) || !tex_orientation)
		return (false);
	if (ft_strncmp(tex_orientation, "NO", 2) == 0)
		target = &map->tex_no;
	else if (ft_strncmp(tex_orientation, "SO", 2) == 0)
		target = &map->tex_so;
	else if (ft_strncmp(tex_orientation, "WE", 2) == 0)
		target = &map->tex_we;
	else if (ft_strncmp(tex_orientation, "EA", 2) == 0)
		target = &map->tex_ea;
	else
		return (false);
	*target = ft_strdup(tex_path);
	if (!*target)
		return (err_msg("Texture init!"), false);
	return (true);
}

bool	dispatch_textures_colors(int fd, t_map *map, int i)
{
	char	*line;
	int		seen[6];

	ft_memset(seen, 0, sizeof(seen));
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			return (err_msg("Missing texture/color data!"), false);
		line = ft_strtrim_parse(line, " \n", 0);
		if (!line)
			return (wait_gnl(fd), err_msg("Memory issue!"), false);
		while (line && check_empty_line(line))
			line = get_next_line(fd);
		if (!parse_line(line, fd, map, seen))
			return (wait_gnl(fd), false);
		i++;
	}
	if (seen[0] + seen[1] + seen[2] + seen[3] + seen[4] + seen[5] != 6)
		return (err_msg("Missing or duplicate texture/color!"), false);
	return (true);
}

// bool	dispatch_textures_colors(int fd, t_map *map, int i)
// {
// 	char	*line;
// 	char	**line_tab;
// 	int		j;
// 	int		seen[6];
// 	char	*clean_path;

// 	j = 0;
// 	while (j < 6)
// 		seen[j++] = 0;
// 	while (i < 6)
// 	{
// 		j = 0;
// 		line = get_next_line(fd);
// 		if (!line)
// 			return (err_msg("Missing texture/color data!"), false);
// 		line = ft_strtrim_parse(line, " \n", 0);
// 		if (!line)
// 			return (wait_gnl(fd), err_msg("Memory issue!"), false);
// 		while (line && check_empty_line(line))
// 			line = get_next_line(fd);
// 		line_tab = ft_split_sp1(line);
// 		free(line);
// 		if (!line_tab)
// 			return (wait_gnl(fd), err_msg("Memory issue!"), false);
// 		while (line_tab[j] && line_tab[j + 1])
// 		{
// 			clean_path = ft_strtrim(line_tab[j + 1], " \t\n\r");
// 			if (!clean_path)
// 				return (wait_gnl(fd), free_array(line_tab),
// 					err_msg("Memory issue!"), false);
// 			if (ft_strncmp(line_tab[j], "NO", 2) == 0 && ++seen[0] == 1)
// 			{
// 				if (!init_textures(line_tab[j], clean_path, map))
// 					return (wait_gnl(fd), free(clean_path),
// 						free_array(line_tab), false);
// 				i++;
// 			}
// 			else if (ft_strncmp(line_tab[j], "SO", 2) == 0 && ++seen[1] == 1)
// 			{
// 				if (!init_textures(line_tab[j], clean_path, map))
// 					return (wait_gnl(fd), free(clean_path),
// 						free_array(line_tab), false);
// 				i++;
// 			}
// 			else if (ft_strncmp(line_tab[j], "WE", 2) == 0 && ++seen[2] == 1)
// 			{
// 				if (!init_textures(line_tab[j], clean_path, map))
// 					return (wait_gnl(fd), free(clean_path),
// 						free_array(line_tab), false);
// 				i++;
// 			}
// 			else if (ft_strncmp(line_tab[j], "EA", 2) == 0 && ++seen[3] == 1)
// 			{
// 				if (!init_textures(line_tab[j], clean_path, map))
// 					return (wait_gnl(fd), free(clean_path),
// 						free_array(line_tab), false);
// 				i++;
// 			}
// 			else if (ft_strncmp(line_tab[j], "F", 1) == 0 && ++seen[4] == 1)
// 			{
// 				if (!init_colors(line_tab[j], clean_path, map))
// 					return (wait_gnl(fd), free(clean_path),
// 						free_array(line_tab), false);
// 				i++;
// 			}
// 			else if (ft_strncmp(line_tab[j], "C", 1) == 0 && ++seen[5] == 1)
// 			{
// 				if (!init_colors(line_tab[j], clean_path, map))
// 					return (wait_gnl(fd), free(clean_path),
// 						free_array(line_tab), false);
// 				i++;
// 			}
// 			else
// 				return (wait_gnl(fd), free(clean_path), free_array(line_tab),
// 					err_msg("Invalid or duplicate texture/color!"), false);
// 			free(clean_path);
// 			j += 2;
// 		}
// 		if (line_tab[j] != NULL)
// 			return (wait_gnl(fd), free_array(line_tab),
// 				err_msg("Incomplete texture/color definition!"), false);
// 		free_array(line_tab);
// 	}
// 	if (seen[0] + seen[1] + seen[2] + seen[3] + seen[4] + seen[5] != 6)
// 		return (wait_gnl(fd),
// 			err_msg("Missing or duplicate required texture/color!"), false);
// 	return (true);
// }