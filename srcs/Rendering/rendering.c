/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:57:52 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/18 18:21:03 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	black_screen(t_mlx *img)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while(x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			my_mlx_pixel_put(img, x, y, 0);
			y++;
		}
		x++;
	}
}

void	draw_square(t_cub *data, int x, int y, int size, int color)
{
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(&data->img[data->active_img], x + i, y, color);
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(&data->img[data->active_img], x, y + i, color);
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(&data->img[data->active_img], x + size, y + i, color);
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(&data->img[data->active_img], x + i, y + size, color);	
}

void	draw_map(t_cub *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == '1')
				draw_square(data, x * 64, y * 64, 64, create_trgb(255, 100, 0, 255));
			x++;
		}
		y++;
	}
}


bool	touch_wall(t_cub *data, int px, int py)
{
	int x = px / 64;
	int y = py / 64;
	if (y > data->map->width || x > data->map->height || y < 0 || x < 0)
		return (true);
	if (data->map->map[y][x] == '1')
		return (true);
	return (false);
}


int	render_next_frame(t_cub *data)
{
	raycaster(data);
	moove_player(data);
	draw_map(data);
	draw_square(data, data->p1->px, data->p1->py, 8, 0x00FF00);
	float ray_x = data->p1->px;
	float ray_y = data->p1->py;
	float cos_pov = cos(data->p1->pov);
	float sin_pov = sin(data->p1->pov);
	while (!touch_wall(data, ray_x, ray_y) && (ray_x < WIN_W && ray_y < WIN_H))
	{
		my_mlx_pixel_put(&data->img[data->active_img], ray_x, ray_y, create_trgb(255, 255, 0, 0));
		ray_x += cos_pov;
		ray_y += sin_pov;
	}
	mlx_put_image_to_window(data->envx->mlx, data->envx->mlx_win,
		data->img[data->active_img].img, 0, 0);
	data->active_img = (data->active_img + 1) % 2;
	black_screen(&data->img[data->active_img]);
	return (0);
}
