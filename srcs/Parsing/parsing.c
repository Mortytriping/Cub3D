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

bool	init_colors(char *f_or_c, char *color, t_map *map)
{
	char	*colors;
	int		i;

	i = 0;
	colors = ft_split(color, ",");
	if (!colors)
		return (false);
	while (colors[i])
		i++;
	if (i != 3)
		return (false);
	if (ft_strncmp(f_or_c, "F", 1) == 0)
	{
		map->floor->t = 255;
		map->floor->r = ft_atoi(colors[0]);
		map->floor->g = ft_atoi(colors[1]);
		map->floor->b = ft_atoi(colors[2]);
		map->floor->color = create_trgb(map->floor->t, map->floor->r,
				map->floor->g, map->floor->b);
	}
	else if (ft_strncmp(f_or_c, "C", 1) == 0)
	{
		map->sky->t = 255;
		map->sky->r = ft_atoi(colors[0]);
		map->sky->g = ft_atoi(colors[1]);
		map->sky->b = ft_atoi(colors[2]);
		map->sky->color = create_trgb(map->sky->t, map->sky->r,
				map->sky->g, map->sky->b);
	}
	return (true);
}


bool	init_textures(char *tex_orientation, char *tex_path, t_map *map)
{
	if (ft_strncmp(tex_orientation, "NO", 2) == 0)
	{
		map->tex_no = ft_strdup(tex_path);
		if (!map->tex_no)
			return (false);
	}
	else if (ft_strncmp(tex_orientation, "SO", 2) == 0)
	{
		map->tex_so = ft_strdup(tex_path);
		if (!map->tex_so)
			return (false);
	}
	else if (ft_strncmp(tex_orientation, "WE", 2) == 0)
	{
		map->tex_we = ft_strdup(tex_path);
		if (!map->tex_we)
			return (false);
	}
	else if (ft_strncmp(tex_orientation, "EA", 2) == 0)
	{
		map->tex_ea = ft_strdup(tex_path);
		if (!map->tex_ea)
			return (false);
	}
	return (true);
}

bool	dispatch_textures_colors(int fd, t_map *map, int i)
{
	char	*line;
	char	**line_tab;
	int		j;
	char	*texture;

	while (i < 6)
	{
		j = 0;
		line = get_next_line(fd);
		if (!line)
			return (ft_putstr_fd("Error: Missing texture/color data!\n", 2),
				false);
		line = ft_strtrim(line, " \n");
		if (!line)
			return (ft_putstr_fd("Error: Memory issue!\n", 2), false);
		line_tab = ft_split(line, " ");
		free(line);
		if (!line_tab)
			return (ft_putstr_fd("Error: Memory issue!\n", 2), false);
		while (line_tab[j] && line_tab[j + 1])
		{
			if (ft_strncmp(line_tab[j], "NO", 2) == 0
				|| ft_strncmp(line_tab[j], "SO", 2) == 0
				|| ft_strncmp(line_tab[j], "WE", 2) == 0
				|| ft_strncmp(line_tab[j], "EA", 2) == 0)
			{
				if (!init_textures(line_tab[j], line_tab[j + 1], &map))
					return (free_array(line_tab),
						ft_putstr_fd("Error: Texture init!", 2), false);
				i++;
			}
			else if (ft_strncmp(line_tab[j], "F", 1) == 0
				|| ft_strncmp(line_tab[j], "C", 1) == 0)
			{
				if (!init_colors(line_tab[j], line_tab[j + 1], &map))
					return (free_array(line_tab),
						ft_putstr_fd("Error: Color init!", 2), false);
				i++;
			}
			else
				return (free_array(line_tab),
					ft_putstr_fd("Error: Invalid texture/color format!\n",
						2), false);
			j += 2;
		}
		if (line_tab[j] != NULL)
			return (free_array(line_tab),
				ft_putstr_fd("Error: Incomplete texture/color definition!\n", 2),
				false);
		free_array(line_tab);
	}
	return (true);
}

char	**cpy_map(char **huge_tab, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (huge_tab[i] != '\0')
		i++;
	map->height = i;
	map->map = malloc(sizeof(char *) * (i + 1));
	if (!map->map)
		return (free_array(huge_tab), NULL);
	while (j < i)
	{
		map->map[j] = ft_strdup(huge_tab[j]);
		j++;
	}
	map->map[j] = NULL;
	return (map->map);
}

bool	check_borders(char **map)
{
}

bool	valid_map(char **huge_tab, t_map *map)
{
	map->map = cpy_map(huge_tab, map);
	if (!map->map)
		return (false);
	if (!check_borders(map->map))
		return (false);
	if (!check_spaces(map->map))
		return (false);
	if (!check_spawn(map->map))
		return (false);
	return (true);
}

bool	init_map(int fd, t_map *map)
{
	char	*line;
	char	**huge_very_huge_tab;
	int		x;

	huge_very_huge_tab = malloc(sizeof(char *) * 10000);
	if (!huge_very_huge_tab)
		return (NULL);
	x = 0;
	line = get_next_line(fd);
	while (line[0] == "\n")
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL && line[0] == "\n")
	{
		line = get_next_line(fd);
		if (!line)
			return (free(line), free_array(huge_very_huge_tab), false);
		huge_very_huge_tab[x] = ft_strdup(line);
		if (!huge_very_huge_tab)
			return (free(line), free_array(huge_very_huge_tab), false);
		x++;
		free(line);
	}
	huge_very_huge_tab[x] = "\0";
	if (!valid_map(huge_very_huge_tab, map))
		return (free_array(huge_very_huge_tab), false);
	return (free_array(huge_very_huge_tab), true);
}

bool	parsing(char **av, int ac, t_cub *data)
{
	int		raw_map;
	int		i;

	i = 0;
	if (!av || ac != 2)
		return (ft_putstr_fd("Error on arguments!\n", 2), false);
	while (av[1][i])
		i++;
	if (i >= 4 && ft_strncmp(av[1] + i - 4, ".cub", 4) == 0)
		;
	else
		return (ft_putstr_fd("Error map is not \".cub\"!\n", 2), false);
	raw_map = open(av[1], O_RDONLY);
	if (raw_map < 0)
		return (ft_putstr_fd("Error can't open the map!\n", 2),
			false);
	if (!dispatch_textures_colors(raw_map, data->map, 0))
		return (close(raw_map), false);
	if (!init_map(raw_map, data->map))
		return (ft_putstr_fd("Error on map initialization!\n", 2),
			close(raw_map), false);
	close (raw_map);
	return (true);
}
