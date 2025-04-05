/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:57:52 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 16:32:23 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_rays(t_cub *data)
{
	int		x;
	float	fov;
	float	angle_increment;
	float	ray_angle;

	fov = FOV * RD;
	angle_increment = fov / WIN_W;
	x = 0;
	while (x < WIN_W)
	{
		ray_angle = data->p1->pov - (fov / 2) + x * angle_increment;
		dda_checker(data, ray_angle, x);
		x++;
	}
}

int	render_next_frame(t_cub *data)
{
	moove_player(data);
	draw_rays(data);
	mlx_put_image_to_window(data->envx->mlx, data->envx->mlx_win,
		data->img[data->active_img].img, 0, 0);
		data->active_img = (data->active_img + 1) % 2;
	return (0);
}

// void	black_screen(t_mlx *img)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x < WIN_W)
// 	{
// 		y = 0;
// 		while (y < WIN_H)
// 		{
// 			my_mlx_pixel_put(img, x, y, 0);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	floor_sky_color(t_mlx *img, t_cub *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x < WIN_W)
// 	{
// 		y = 0;
// 		while (y < WIN_H)
// 		{
// 			if (y < (WIN_H / 2))
// 				my_mlx_pixel_put(img, x, y, data->map->sky->color);
// 			else
// 				my_mlx_pixel_put(img, x, y, data->map->floor->color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	draw_cercle(t_cub *data, int cx, int cy, int size, int color)
// {
// 	int y = -size;
//     while (y <= size)
//     {
//         int x = -size;
//         while (x <= size)
//         {
//             if (x * x + y * y <= size * size)
//                 my_mlx_pixel_put(&data->img[data->active_img],
// 					cx + x, cy + y, color);
//             x++;
//         }
//         y++;
//     }
// }

// void	draw_square(t_cub *data, int x, int y, int size, int color)
// {
// 	int	i;
// 	int	v;
// 	v = size - 1;
// 	while (v)
// 	{
// 		i = size - 1;
// 		while (i > 0)
// 		{
// 			my_mlx_pixel_put(&data->img[data->active_img],
// 				x + i, y + v, color);
// 			i--;
// 		}
// 		v--;
// 	}
// }

// void	draw_map(t_cub *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (data->map->map[y])
// 	{
// 		x = 0;
// 		while (data->map->map[y][x])
// 		{
// 			if (data->map->map[y][x] == '1')
// 				draw_square(data, x * SCALE_BLOCK, y * SCALE_BLOCK,
// 					SCALE_BLOCK, create_trgb(0, 100, 0, 255));
// 			else if (ft_strchr("0NWSE", data->map->map[y][x]))
// 				draw_square(data, x * SCALE_BLOCK, y * SCALE_BLOCK,
// 					SCALE_BLOCK, data->map->floor->color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	player_point_dir(t_cub *data)
// {
// 	int		i;
// 	float	ray_x;
// 	float	ray_y;
// 	float	cos_pov;
// 	float	sin_pov;

// 	i = SCALE_BLOCK / 2;
// 	cos_pov = cos(data->p1->pov);
// 	sin_pov = sin(data->p1->pov);
// 	ray_x = data->p1->px;
// 	ray_y = data->p1->py;
// 	while (i)
// 	{
// 		my_mlx_pixel_put(&data->img[data->active_img], ray_x, ray_y, 0x99099);
// 		ray_x += cos_pov;
// 		ray_y += sin_pov;
// 		i--;
// 	}
// }

// draw_map(data);
// draw_cercle(data, data->p1->px, data->p1->py, SCALE_BLOCK / 5, 0x99099);
// player_point_dir(data);
