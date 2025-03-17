/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:52:36 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/17 15:49:19 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBD3D_H
# define CUBD3D_H

/*---------------------includes---------------------*/

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <stdbool.h>

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
	int	R;
	int	G;
	int	B;
}	t_colors;

typedef struct s_player
{
	float	px;
	float	py;
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
	int			width;
    int			height;
}	t_map;

/*---------------main data structure---------------*/

typedef struct s_cub
{
	t_envx		*envx;
	t_mlx		img;
	int 		win_width;
	int 		win_height;
	t_player	*p1;
	t_map		*map;
}	t_cub;

/*-----------fonctions declarations start-----------*/

/*------main------*/

/*-----colors-----*/
void	trunc_error_rgb(int *r, int *g, int *b);

/*-----freeing-----*/
void	last_free_uninit_data(t_cub *data);

/*-----init_data-----*/
t_cub	*init_data(void);

/*-----inputs-----*/

/*-----parsing-----*/

/*---Raycasting---*/

/*----Rendering----*/

/*------utils------*/
void	err_msg(char *str);

/*----mlx_utils----*/
void	init_win_img(t_cub *data);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		close_win(t_envx *env);
void	end_mlx(t_cub *data);

/*------------fonctions declarations end------------*/

#endif