#include "../../includes/cub3d.h"

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
