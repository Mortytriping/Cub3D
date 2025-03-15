/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:52:36 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/15 15:16:56 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBD3D_H
# define CUBD3D_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

/*----------mlx_init_structures----------*/

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

/*-----------others structures-----------*/

typedef struct s_colors
{
	int	R;
	int	G;
	int	B;
} t_colors;

typedef struct s_player
{
	float	px;
	float	py;
} t_player;

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
    int   		height;
} t_map;

/*-----------main data structure-----------*/

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_win;
	t_mlx		img;
	int 		win_width;
	int 		win_height;
	t_player	*p1;
	t_map		*map;
} t_cub;

/*-----------fonctions declarations-----------*/

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

#endif