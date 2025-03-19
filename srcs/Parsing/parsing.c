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
		return (err_msg("Map is not a \".cub\" file!"), false);
	raw_map = open(av[1], O_RDONLY);
	if (raw_map < 0)
		return (err_msg("Can't open the map!"), false);
	if (!dispatch_textures_colors(raw_map, data->map, 0))
		return (close(raw_map), false);
	if (!init_map(raw_map, data->map, data))
		return (err_msg("Map initialization failed!"),
			close(raw_map), false);
	close (raw_map);
	return (true);
}
