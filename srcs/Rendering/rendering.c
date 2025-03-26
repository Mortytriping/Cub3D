/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:57:52 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/26 12:46:38 by apouesse         ###   ########.fr       */
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

void	draw_cercle(t_cub *data, int cx, int cy, int size, int color)
{
	int y = -size;
    while (y <= size)
    {
        int x = -size;
        while (x <= size)
        {
            if (x * x + y * y <= size * size)
                my_mlx_pixel_put(&data->img[data->active_img], cx + x, cy + y, color);
            x++;
        }
        y++;
    }
}

void	draw_square(t_cub *data, int x, int y, int size, int color)
{
	int	i;
	int	v;
	v = size - 1;
	while (v)
	{
		i = size - 1;
		while (i > 0)
		{
			my_mlx_pixel_put(&data->img[data->active_img], x + i, y + v, color);
			i--;
		}
		v--;
	}
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
				draw_square(data, x * SCALE_BLOCK, y * SCALE_BLOCK, SCALE_BLOCK, create_trgb(0, 100, 0, 255));
			else if (ft_strchr("0NWSE", data->map->map[y][x]))
				draw_square(data, x * SCALE_BLOCK, y * SCALE_BLOCK, SCALE_BLOCK, data->map->floor->color);
			x++;
		}
		y++;
	}
}

void	player_point_dir(t_cub *data)
{
	int		i;
	float	ray_x;
	float	ray_y;
	float	cos_pov;
	float	sin_pov;

	i = SCALE_BLOCK / 2;
	cos_pov = cos(data->p1->pov);
	sin_pov = sin(data->p1->pov);
	ray_x = data->p1->px;
	ray_y = data->p1->py;
	while (i)
	{
		my_mlx_pixel_put(&data->img[data->active_img], ray_x, ray_y, 0x99099);
		ray_x += cos_pov;
		ray_y += sin_pov;
		i--;
	}
}

int	render_next_frame(t_cub *data)
{
	int c;
	float	fraction;
	float	start_x;

	raycaster(data);
	moove_player(data);
	draw_map(data);
	draw_cercle(data, data->p1->px, data->p1->py, SCALE_BLOCK / 5, 0x99099);
	player_point_dir(data);
	fraction =  PI / 3 / WIN_H;
	start_x = data->p1->pov - PI / 6;
	c = 0;
	while (c < WIN_W)
	{
		draw_rays(data, start_x, c);
		start_x += fraction; 
		c++;
	}
	mlx_put_image_to_window(data->envx->mlx, data->envx->mlx_win,
		data->img[data->active_img].img, 0, 0);
	data->active_img = (data->active_img + 1) % 2;
	black_screen(&data->img[data->active_img]);
	return (0);
}
