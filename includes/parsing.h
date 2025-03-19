#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include "cub3d.h"
# include "../libft/libft.h"

typedef struct s_cub	t_cub;
typedef struct s_map	t_map;

/*---------------parsing---------------*/

bool	parsing(char **av, int ac, t_cub *data);

/*---------------map---------------*/

char	**cpy_map(char **huge_tab, t_map *map);
bool	init_map(int fd, t_map *map, t_cub *data);

void	find_maxs(t_map *map);
bool	check_inside(char **map);
bool	check_borders(char **map, t_cub *data);
bool	check_player(char **map, t_cub *data, int player);
bool	valid_map(char **huge_tab, t_map *map, t_cub *data);

/*---------------textures and colors---------------*/

bool	dispatch_textures_colors(int fd, t_map *map, int i);

bool	init_colors(char *f_or_c, char *color, t_map *map);
bool	init_textures(char *tex_orientation, char *tex_path, t_map *map);

#endif