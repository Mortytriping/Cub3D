/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:52:36 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/27 11:02:50 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*---------------------includes---------------------*/

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include "parsing.h"
# include <X11/X.h>

/*---------------------Macros---------------------*/

# define WIN_W 1024
# define WIN_H 720


# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define PI 3.14159265359
# define RD 0.01745329
# define NO 3 * PI / 2
# define SU PI / 2
# define WE PI
# define EA 0

/*-------------settings------------*/

# define FOV 60
# define SCALE_BLOCK 16
# define SPEED 0.3

/*-------------Player settings end------------*/

/*---------------mlx_init_structures---------------*/

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_envx
{
	void		*mlx;
	void		*mlx_win;
}	t_envx;

/*----------------others structures----------------*/

typedef struct s_colors
{
	int	t;
	int	r;
	int	g;
	int	b;
	int color; 	//utiliser create_trgb(t, r, g, b) pour creer la couleur; 
} t_colors;

typedef struct s_player
{
	float	px;
	float	py;
	char	orientation;
	float	pov;
	bool	moove_up;
	bool	moove_left;
	bool	moove_down;
	bool	moove_right;
	bool	rotate_left;
	bool	rotate_right;
}	t_player;

typedef struct	s_map
{
	char		**map;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	t_colors	*floor;
	t_colors	*sky;
	int   		width;
	int			height;
} t_map;

/*---------------main data structure---------------*/

typedef struct s_cub
{
	t_envx		*envx;
	t_mlx		img[2];
	int			active_img;
	int 		win_width;
	int 		win_height;
	t_player	*p1;
	t_map		*map;
}	t_cub;

/*-----------fonctions declarations start-----------*/

/*------main------*/

/*-----colors-----*/
void	trunc_error_rgb(int *t, int *r, int *g, int *b);
int		create_trgb(int t, int r, int g, int b);

/*-----freeing-----*/
void	last_free_uninit_data(t_cub *data);
void	free_textures(t_map *map);

/*-----init_data-----*/
t_cub	*init_data(void);

/*-----inputs-----*/
int		keyboard_events(int keycode, t_cub *data);
int		key_release(int keycode, t_cub *data);
int		key_press(int keycode, t_cub *data);

/*-----parsing-----*/

/*-----player-----*/
void	init_player(t_cub *data);
void	moove_player(t_cub *data);

/*---Raycasting---*/
void	raycaster(t_cub *data);
void	draw_rays(t_cub *data, float start_x, int i);

/*----Rendering----*/
int		render_next_frame(t_cub *data);
void	draw_cercle(t_cub *data, int cx, int cy, int size, int color);

/*------utils------*/
void	err_msg(char *str);
void	free_array(char **array);

/*----mlx_utils----*/
void	init_win_img(t_cub *data);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		close_win(t_envx *env);
void	end_mlx(t_cub *data);

/*------------fonctions declarations end------------*/

#endif