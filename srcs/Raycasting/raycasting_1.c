/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:40:22 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/28 19:12:34 by apouesse         ###   ########.fr       */
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

void	raycasting(t_cub *data, t_dda r, int x)
{
	if (r.h_wall_size < r.v_wall_size)
		r.dist = r.h_wall_size;
	else
		r.dist = r.v_wall_size;
	r.height = (SCALE_BLOCK / r.dist) * (WIN_W / 2);
	r.start = (WIN_H - r.height) / 2;
	r.end = r.start + r.height;
	while (r.start < r.end)
	{
		my_mlx_pixel_put(&data->img[data->active_img] , x, r.start, create_trgb(0, 150, 0, 255));
		r.start++;
	}
}

void	dda_checker(t_cub *data, float ray_a, int x)
{
	t_dda	r;
	
	if (sin(ray_a) != 0)
	{
		r.max_iter = 0;
		r.hit = 0;
		if (sin(ray_a) > 0)
		{
			r.first_y = floor(data->p1->py / SCALE_BLOCK) * SCALE_BLOCK + SCALE_BLOCK;
			r.y_step = SCALE_BLOCK;
		}
		else
		{
			r.first_y = floor(data->p1->py / SCALE_BLOCK) * SCALE_BLOCK - 0.0001;
			r.y_step = -SCALE_BLOCK;
		}
		r.first_x = data->p1->px + (r.first_y - data->p1->py) / tan(ray_a);
		r.x_step = r.y_step / tan(ray_a);
		while (r.max_iter < 10)
		{
			r.map_x = (int)r.first_x / SCALE_BLOCK;
			r.map_y = (int)r.first_y / SCALE_BLOCK;
			
			if (r.map_x < 0 || r.map_x >= data->map->width ||
				r.map_y < 0 || r.map_y >= data->map->height)
				break ;
			
			if (data->map->map[r.map_y][r.map_x] == '1')
			{
				r.hit = 1;
				break ;
			}
			r.first_x = r.first_x + r.x_step;
			r.first_y = r.first_y + r.y_step;
			r.max_iter++;
		}
		if (r.hit)
		{
			r.p1.x = data->p1->px;
			r.p1.y = data->p1->py;
			r.p2.x = r.first_x;
			r.p2.y = r.first_y;
			draw_bresenham(r.p1, r.p2, data, 0xFF0000);
		}
		r.h_wall_size = distance(data, r.p2.x, r.p2.y);
	}
	else
		r.h_wall_size = -1;
	/*----------------------verticale lignes-------------------------*/
	r.max_iter = 0;
	r.hit = 0;
	if (cos(ray_a) != 0)
	{
		
		if (cos(ray_a) > 0)
		{
			r.first_x = floor(data->p1->px / SCALE_BLOCK) * SCALE_BLOCK + SCALE_BLOCK;
			r.x_step = SCALE_BLOCK;
		}
		else
		{
			r.first_x = floor(data->p1->px / SCALE_BLOCK) * SCALE_BLOCK - 0.0001;
			r.x_step = -SCALE_BLOCK;
		}
		r.first_y = data->p1->py + (r.first_x - data->p1->px) * tan(ray_a);
		r.y_step = r.x_step * tan(ray_a);
		while (r.max_iter < 10)
		{
			r.map_x = (int)r.first_x / SCALE_BLOCK;
			r.map_y = (int)r.first_y / SCALE_BLOCK;			
			if (r.map_x < 0 || r.map_x >= data->map->width ||
				r.map_y < 0 || r.map_y >= data->map->height)
				break ;
			
			if (data->map->map[r.map_y][r.map_x] == '1')
			{
				r.hit = 1;
				break ;
			}
			r.first_x = r.first_x + r.x_step;
			r.first_y = r.first_y + r.y_step;
			r.max_iter++;
		}
		if (r.hit)
		{
			r.p1.x = data->p1->px;
			r.p1.y = data->p1->py;
			r.p2.x = r.first_x;
			r.p2.y = r.first_y;
			draw_bresenham(r.p1, r.p2, data, 0x00FF00);
		}
		r.v_wall_size = distance(data, r.p2.x, r.p2.y);
	}
	else
		r.v_wall_size = -1;
	raycasting(data, r, x);
}

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
