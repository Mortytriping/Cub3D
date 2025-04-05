/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:40:22 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 16:37:29 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	raycasting_1(t_raycasting *vars, t_dda *r, float ray_a)
{
	r->dist = r->h_wall_size;
	vars->side = 1;
	if (sin(ray_a) < 0)
		vars->tex = NORD;
	else
		vars->tex = SUD;
	vars->wall_x = ((float)r->h_p.x / (float)SCALE_BLOCK);
	vars->wall_x -= floorf(vars->wall_x);
}

void	raycasting_2(t_raycasting *vars, t_dda *r, float ray_a)
{
	vars->side = 0;
	r->dist = r->v_wall_size;
	if (cos(ray_a) > 0)
		vars->tex = EST;
	else
		vars->tex = OUEST;
	vars->wall_x = ((float)r->v_p.y / (float)SCALE_BLOCK);
	vars->wall_x -= floorf(vars->wall_x);
}

void	raycasting_3(t_raycasting *vars, t_dda *r, t_cub *data, int x)
{
	if (r->dist < 0.1)
		r->dist = 0.1;
	vars->tex_x = (vars->wall_x * data->textures[vars->tex].width);
	r->height = (SCALE_BLOCK / r->dist) * (WIN_W / 2);
	r->start = (WIN_H - r->height) / 2;
	r->end = r->start + r->height;
	vars->step = data->textures[vars->tex].height / r->height;
	vars->texpos = (r->start - (WIN_H / 2 - r->height / 2)) * vars->step;
	if (vars->texpos < 0)
		vars->texpos = 0;
	vars->i = 0;
	while (vars->i < r->start)
	{
		my_mlx_pixel_put(&data->img[data->active_img],
			x, vars->i, data->map->sky->color);
		vars->i++;
	}
	if (r->end > WIN_H)
		r->end = WIN_H;
	if (r->start < 0)
	{
		vars->texpos += vars->step * (-r->start);
		r->start = 0;
	}
}

void	raycasting_4(t_raycasting *vars, t_dda *r, t_cub *data, int x)
{
	vars->tex_y = (int)vars->texpos % data->textures[vars->tex].height;
	if (vars->tex_y < 0)
		vars->tex_y += data->textures[vars->tex].height;
	vars->texpos += vars->step;
	vars->w_color = *(int *)(data->textures[vars->tex].addr
			+ ((int)vars->tex_y * data->textures[vars->tex].line_length)
			+ ((int)vars->tex_x * (data->textures[vars->tex].bpp / 8)));
	my_mlx_pixel_put(&data->img[data->active_img], x,
		r->start, vars->w_color);
	r->start++;
}

void	raycasting(t_cub *data, t_dda r, int x, float ray_a)
{
	t_raycasting	vars;

	if ((r.h_wall_size - r.v_wall_size) < 0.001)
		raycasting_1(&vars, &r, ray_a);
	else
		raycasting_2(&vars, &r, ray_a);
	raycasting_3(&vars, &r, data, x);
	while (r.start < r.end)
		raycasting_4(&vars, &r, data, x);
	vars.i = r.end;
	while (vars.i < WIN_H)
	{
		my_mlx_pixel_put(&data->img[data->active_img], x, vars.i,
			data->map->floor->color);
		vars.i++;
	}
}
