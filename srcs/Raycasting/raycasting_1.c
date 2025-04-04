/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:40:22 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/04 18:39:40 by apouesse         ###   ########.fr       */
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

float	distance(t_cub *data, float ray_x, float ray_y, float ray_a)
{
	float	delta_x;
	float	delta_y;
	float	fix_dist;

	delta_x = ray_x - data->p1->px;
	delta_y = ray_y - data->p1->py;
	fix_dist = clc_dist(delta_x, delta_y) * cos(ray_a - data->p1->pov);
	if (fix_dist < 1.0)
		fix_dist = 1.0;
	return (fix_dist);;
}

void	raycasting(t_cub *data, t_dda r, int x, float ray_a)
{
	int		w_color;
	int		side;
	int		i;
	int		tex;
	float	wall_x;	
	float	tex_x;
	float	tex_y;
	float	step;
	float   texPos;

	
	i = 0;
	if ((r.h_wall_size - r.v_wall_size) < 0.001)
	{
		r.dist = r.h_wall_size;
		side = 1;
		if (sin(ray_a) < 0)
			tex = NORD;
		else
			tex = SUD;
		wall_x = ((float)r.h_p.x / (float)SCALE_BLOCK);
		wall_x -= floorf(wall_x);
	}
	else
	{
		side = 0;
		r.dist = r.v_wall_size;
		if (cos(ray_a) > 0)
			tex = EST;
		else
			tex = OUEST;
		wall_x = ((float)r.v_p.y / (float)SCALE_BLOCK);
		wall_x -= floorf(wall_x);
	}
	if (r.dist < 0.1)
    	r.dist = 0.1;
	tex_x = (wall_x * data->textures[tex].width);
	r.height = (SCALE_BLOCK / r.dist) * (WIN_W / 2);
	r.start = (WIN_H - r.height) / 2;
	r.end = r.start + r.height;
	step = data->textures[tex].height / r.height;
	texPos = (r.start - (WIN_H / 2 - r.height / 2)) * step;
	if (texPos < 0)
		texPos = 0; 
	while (i < r.start)
	{
		my_mlx_pixel_put(&data->img[data->active_img] , x, i, data->map->sky->color);
		i++;
	}
	while (r.start < r.end)
	{
		tex_y = (int)texPos % data->textures[tex].height;
		if (tex_y < 0)
			tex_y += data->textures[tex].height;
		texPos += step;

		// Récupérer la couleur de la texture :
		// On utilise *(int *) pour lire la valeur
		w_color = *(int *)(data->textures[tex].addr
			+ ((int)tex_y * data->textures[tex].line_length)
			+ ((int)tex_x * (data->textures[tex].bpp / 8)));
		my_mlx_pixel_put(&data->img[data->active_img], x, r.start, w_color);
		r.start++;
	}
	i = r.end;
	while (i < WIN_H)
	{
		my_mlx_pixel_put(&data->img[data->active_img] , x, i, data->map->floor->color);
		i++;
	}
}

void	dda_checker(t_cub *data, float ray_a, int x)
{
	t_dda	r;
	
	if (fabs((sin(ray_a))) > 0.0001)
	{
		r.max_iter = 0;
		r.hit = 0;
		if (sin(ray_a) > 0.0001)
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
		while (r.max_iter < 100)
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
			// r.p1.x = data->p1->px;
			// r.p1.y = data->p1->py;
			r.h_p.x = r.first_x;
			r.h_p.y = r.first_y;
			// draw_bresenham(r.p1, r.h_p, data, 0xFF0000);
			r.h_wall_size = distance(data, r.h_p.x, r.h_p.y, ray_a);
		}
		else
			r.h_wall_size = 1e30;
	}
	else
		r.h_wall_size = 1e30;
	/*----------------------verticale lignes-------------------------*/
	r.max_iter = 0;
	r.hit = 0;
	if (fabs(cos(ray_a)) > 0.0001)
	{
		
		if (cos(ray_a) > 0.0001)
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
		while (r.max_iter < 100)
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
			// r.p1.x = data->p1->px;
			// r.p1.y = data->p1->py;
			r.v_p.x = r.first_x;
			r.v_p.y = r.first_y;
			// draw_bresenham(r.p1, r.v_p, data, 0x00FF00);
			r.v_wall_size = distance(data, r.v_p.x, r.v_p.y, ray_a);
		}
		else
			r.v_wall_size = 1e30;
	}
	else
		r.v_wall_size = 1e30;
	raycasting(data, r, x, ray_a);
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
