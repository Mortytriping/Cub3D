/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:40:22 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/27 16:48:19 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ray_touch_wall(t_cub *data, int px, int py)
{
	int x;
	int y;
	x = px / SCALE_BLOCK;
	y = py / SCALE_BLOCK;
	if (x > data->map->width - 1 || y > data->map->height - 1 || y < 0 || x < 0)
		return (true);
	if (data->map->map[y][x] == '1')
		return (true);
	return (false);
}

float	clc_dist(float x, float y)
{
	return (sqrt((x * x) + (y * y)));
}

float	distance(t_cub *data, float ray_x, float ray_y)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = ray_x - data->p1->px;
	delta_y = ray_y - data->p1->py;
	angle = atan2(delta_y, delta_x) - data->p1->pov;
	fix_dist = clc_dist(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}


void	dda_checker(t_cub *data)
{
	float	y_step;
	float	x_step;
	float	first_x;
	float	first_y;
	// float	r_angle;
	float	tang;
	float	ray_a;
	// int		ray_nb;
	int		r_field;
	int		max_x;
	int		max_y;
	int		max_p;
	t_point		p1;
	t_point		p2;

	r_field = 0;
	ray_a = data->p1->pov;
	tang = -1 / tan(ray_a);
	if (ray_a > PI) //looking down
	{
		first_y = (((int)data->p1->py >> 6) << 6) - 0.0001;
		first_x = data->p1->py - first_y * tang + data->p1->px;
		y_step = -64;
		x_step = 64 * tang;
	}
	if (ray_a < PI) //looking up
	{
		first_y = (((int)data->p1->py >> 6) << 6) +64;
		first_x = data->p1->py - first_y * tang + data->p1->px;
		y_step = 64;
		x_step = -64 * tang;
	}
	if (ray_a == 0 || ray_a == PI)
	{
		first_x = data->p1->px;
		first_y = data->p1->py;
		r_field = 10;
	}
	while (r_field < 10)
	{
		max_x = (int)(first_x) >> 6;
		max_y = (int)(first_y) >> 6;
		max_p = max_y * data->map->width + max_x;
		if (max_p < data->map->width * data->map->height && data->map->map[max_y][max_x] == '1')
			r_field = 10;
		else
		{
			p1.x = first_x;
			p2.x = first_x += x_step;
			p1.y = first_y;
			p2.y = first_y += y_step;
			// first_x += x_step;
			// first_y += y_step;
		}
		draw_bresenham(p1, p2, data);
		r_field++;
	}
}

void	draw_rays(t_cub *data, float start_x, int i)
{
	float	sin_pov;
	float	cos_pov;
	float	ray_y;
	float	ray_x;
	float	dist;
	float	height;
	int		start_y;
	int 	end;
	

	ray_x = data->p1->px;
	ray_y = data->p1->py;
	cos_pov = cos(start_x);
	sin_pov = sin(start_x);
	// while (!ray_touch_wall(data, ray_x, ray_y) && (ray_x < WIN_W && ray_y < WIN_H)) //a remplacer par un DDA algo pour otpi (force a nous);
	// {
	// 	my_mlx_pixel_put(&data->img[data->active_img], ray_x, ray_y, create_trgb(0, 255, 0, 0));
	// 	ray_x += cos_pov;
	// 	ray_y += sin_pov;
	// }
	dda_checker(data);
	(void)i;
	dist = distance(data, ray_x, ray_y);
	height = (SCALE_BLOCK / dist) * (WIN_W / 2);
	start_y = (WIN_H - height) / 2;
	end = start_y + height;
	while (start_y < end)
	{
		my_mlx_pixel_put(&data->img[data->active_img], i, start_y, create_trgb(0, 0, 0, 255));
		start_y++;
	}
}


void	raycaster(t_cub *data)
{
	(void)data;
}
