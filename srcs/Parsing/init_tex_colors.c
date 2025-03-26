#include "../../includes/cub3d.h"

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
			return (err_msg("Color init!"), false);
		i++;
	}
	if (i != 3)
		return (err_msg("Color init!"), false);
	if (ft_strncmp(f_or_c, "F", 1) == 0)
	{
		map->floor->t = 0;
		map->floor->r = ft_atol(colors[0]);
		map->floor->g = ft_atol(colors[1]);
		map->floor->b = ft_atol(colors[2]);
		map->floor->color = create_trgb(map->floor->t, map->floor->r,
				map->floor->g, map->floor->b);
	}
	else if (ft_strncmp(f_or_c, "C", 1) == 0)
	{
		map->sky->t = 0;
		map->sky->r = ft_atol(colors[0]);
		map->sky->g = ft_atol(colors[1]);
		map->sky->b = ft_atol(colors[2]);
		map->sky->color = create_trgb(map->sky->t, map->sky->r,
				map->sky->g, map->sky->b);
	}
	if (ft_atol(colors[0]) > INT_MAX || ft_atol(colors[0]) < INT_MIN
		|| ft_atol(colors[1]) > INT_MAX || ft_atol(colors[1]) < INT_MIN
		|| ft_atol(colors[2]) > INT_MAX || ft_atol(colors[2]) < INT_MIN)
		return (err_msg("Color init!"), false);
	return (true);
}

bool	init_textures(char *tex_orientation, char *tex_path, t_map *map)
{
	if (!tex_path || !valid_path(tex_path) || !tex_orientation)
		return (false);
	if (ft_strncmp(tex_orientation, "NO", 2) == 0)
	{
		map->tex_no = ft_strdup(tex_path);
		if (!map->tex_no)
			return (err_msg("Texture init!"), false);
	}
	else if (ft_strncmp(tex_orientation, "SO", 2) == 0)
	{
		map->tex_so = ft_strdup(tex_path);
		if (!map->tex_so)
			return (err_msg("Texture init!"), false);
	}
	else if (ft_strncmp(tex_orientation, "WE", 2) == 0)
	{
		map->tex_we = ft_strdup(tex_path);
		if (!map->tex_we)
			return (err_msg("Texture init!"), false);
	}
	else if (ft_strncmp(tex_orientation, "EA", 2) == 0)
	{
		map->tex_ea = ft_strdup(tex_path);
		if (!map->tex_ea)
			return (err_msg("Texture init!"), false);
	}
	return (true);
}

bool	check_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (false);
		i++;
	}
	free(line);
	return (true);
}

bool	dispatch_textures_colors(int fd, t_map *map, int i)
{
	char	*line;
	char	**line_tab;
	int		j;
	int		seen[6];

	j = 0;
	while (j < 6)
		seen[j++] = 0;
	while (i < 6)
	{
		j = 0;
		line = get_next_line(fd);
		if (!line)
			return (err_msg("Missing texture/color data!"), false);
		line = ft_strtrim(line, " \n");
		if (!line)
			return (err_msg("Memory issue!"), false);
		while (line && check_empty_line(line))
			line = get_next_line(fd);
		line_tab = ft_split_sp1(line);
		free(line);
		if (!line_tab)
			return (err_msg("Memory issue!"), false);
		while (line_tab[j] && line_tab[j + 1])
		{
			// Nettoyage du chemin de texture
			char *clean_path = ft_strtrim(line_tab[j + 1], " \t\n\r");
			if (!clean_path)
				return (free_array(line_tab), err_msg("Memory issue!"), false);
			
			if (ft_strncmp(line_tab[j], "NO", 2) == 0 && ++seen[0] == 1)
			{
				if (!init_textures(line_tab[j], clean_path, map))
					return (free(clean_path), free_array(line_tab), false);
				i++;
			}
			else if (ft_strncmp(line_tab[j], "SO", 2) == 0 && ++seen[1] == 1)
			{
				if (!init_textures(line_tab[j], clean_path, map))
					return (free(clean_path), free_array(line_tab), false);
				i++;
			}
			else if (ft_strncmp(line_tab[j], "WE", 2) == 0 && ++seen[2] == 1)
			{
				if (!init_textures(line_tab[j], clean_path, map))
					return (free(clean_path), free_array(line_tab), false);
				i++;
			}
			else if (ft_strncmp(line_tab[j], "EA", 2) == 0 && ++seen[3] == 1)
			{
				if (!init_textures(line_tab[j], clean_path, map))
					return (free(clean_path), free_array(line_tab), false);
				i++;
			}
			else if (ft_strncmp(line_tab[j], "F", 1) == 0 && ++seen[4] == 1)
			{
				if (!init_colors(line_tab[j], clean_path, map))
					return (free(clean_path), free_array(line_tab), false);
				i++;
			}
			else if (ft_strncmp(line_tab[j], "C", 1) == 0 && ++seen[5] == 1)
			{
				if (!init_colors(line_tab[j], clean_path, map))
					return (free(clean_path), free_array(line_tab), false);
				i++;
			}
			else
				return (free(clean_path), free_array(line_tab),
					err_msg("Invalid or duplicate texture/color!"), false);
			free(clean_path);
			j += 2;
		}
		if (line_tab[j] != NULL)
			return (free_array(line_tab),
				err_msg("Incomplete texture/color definition!"), false);
		free_array(line_tab);
	}
	if (seen[0] + seen[1] + seen[2] + seen[3] + seen[4] + seen[5] != 6)
		return (err_msg("Missing or duplicate required texture/color!"), false);
	return (true);
}
