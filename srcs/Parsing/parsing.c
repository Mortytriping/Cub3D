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
		{
			free_array(line_tab);
			return (
				ft_putstr_fd("Error: Incomplete texture/color definition!\n", 2),
				false);
		}
		free_array(line_tab);
	}
	return (true);
}

bool	parsing(char **av, int ac, t_cub *data)
{
	int	raw_map;
	int	i;

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
			close(raw_map), false);
	if (!init_textures_colors(raw_map, data->map))
		return (ft_putstr_fd("Error on textures initialization!\n", 2), false);
	if (!init_map(raw_map, data->map))
		return (ft_putstr_fd("Error on map initialization!\n", 2), false);
	close (raw_map);
	return (true);
}
