/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:52:36 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 17:06:14 by apouesse         ###   ########.fr       */
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

# define WIN_W 1280
# define WIN_H 860

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define PI 3.14159265359
# define RD 0.01745329
# define NO 4.7123889804
# define SU 1.5707963268
# define WE PI
# define EA 0

# define NORD 0
# define SUD 1
# define EST 2
# define OUEST 3

/*-------------settings------------*/

# define FOV 60
# define SCALE_BLOCK 64
# define SPEED 0.8

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

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_texture;

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
	int	color;
}	t_colors;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_bresenhem
{
	int		diff_x;
	int		diff_y;
	int		step_x;
	int		step_y;
	int		error;
	int		y;
	int		x;
	int		i;
}	t_bresenham;

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

typedef struct s_map
{
	char		**map;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	t_colors	*floor;
	t_colors	*sky;
	int			width;
	int			height;
}	t_map;

typedef struct s_dda
{
	float	h_wall_size;
	float	v_wall_size;
	float	dist;
	float	height;
	int		start;
	int		end;
	float	first_x;
	float	first_y;
	float	x_step;
	float	y_step;
	int		map_x;
	int		map_y;
	int		max_iter;
	int		hit;
	int		w_color;
	t_point	p1;
	t_point	h_p;
	t_point	v_p;
}	t_dda;

typedef struct s_raycasting
{
	int		w_color;
	int		side;
	int		i;
	int		tex;
	float	wall_x;	
	float	tex_x;
	float	tex_y;
	float	step;
	float	texpos;
}	t_raycasting;

/*---------------main data structure---------------*/

typedef struct s_cub
{
	t_envx		*envx;
	t_mlx		img[2];
	t_texture	textures[4];
	int			active_img;
	int			win_width;
	int			win_height;
	t_player	*p1;
	t_map		*map;
}	t_cub;

/*-----------fonctions declarations start-----------*/

/*-----colors-----*/
void	trunc_error_rgb(int *t, int *r, int *g, int *b);
int		create_trgb(int t, int r, int g, int b);

/*-----freeing-----*/
void	last_free_uninit_data(t_cub *data);
void	free_textures(t_map *map);
void	free_last_er(t_cub *data);

/*-----init_data-----*/
t_cub	*init_data(void);

/*-----inputs-----*/
int		keyboard_events(int keycode, t_cub *data);
int		key_release(int keycode, t_cub *data);
int		key_press(int keycode, t_cub *data);

/*-----player-----*/
void	init_player(t_cub *data);
void	moove_player(t_cub *data);

/*---Raycasting---*/
void	dda_checker(t_cub *data, float ray_a, int x);
void	raycasting(t_cub *data, t_dda r, int x, float ray_a);
void	draw_rays(t_cub *data);
bool	ray_touch_wall(t_cub *data, int px, int py);
void	dda_h_1(t_dda *r, t_cub *data, float ray_a);
void	dda_h_2(t_dda *r, t_cub *data);
void	dda_v_1(t_dda *r, t_cub *data, float ray_a);
void	dda_v_2(t_dda *r, t_cub *data);

/*----Rendering----*/
int		render_next_frame(t_cub *data);
// void	floor_sky_color(t_mlx *img, t_cub *data);
// void	draw_cercle(t_cub *data, int cx, int cy, int size, int color);

/*------utils------*/
float	distance(t_cub *data, float ray_x, float ray_y, float ray_a);
float	clc_dist(float x, float y);
void	err_msg(char *str);
void	free_array(char **array);

/*----mlx_utils----*/
bool	init_win_img(t_cub *data);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		close_win(t_envx *env);
void	end_mlx(t_cub *data);
bool	init_texture(t_cub *data);
bool	load_texture(t_cub *data, char *path, t_texture *texture);

/*----bresenham----*/
void	draw_bresenham(t_point p1, t_point p2, t_cub *data, int color);

/*------------fonctions declarations end------------*/

#endif