/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:26:30 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 16:31:30 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ray_touch_wall(t_cub *data, int px, int py)
{
	int	x;
	int	y;

	x = px / SCALE_BLOCK;
	y = py / SCALE_BLOCK;
	if (x > data->map->width - 1 || y
		> data->map->height - 1 || y < 0 || x < 0)
		return (true);
	if (data->map->map[y][x] == '1')
		return (true);
	return (false);
}

void	dda_h_1(t_dda *r, t_cub *data, float ray_a)
{
	r->max_iter = 0;
	r->hit = 0;
	if (sin(ray_a) > 0.0001)
	{
		r->first_y = floor(data->p1->py / SCALE_BLOCK)
			* SCALE_BLOCK + SCALE_BLOCK;
		r->y_step = SCALE_BLOCK;
	}
	else
	{
		r->first_y = floor(data->p1->py / SCALE_BLOCK) * SCALE_BLOCK - 0.0001;
		r->y_step = -SCALE_BLOCK;
	}
	r->first_x = data->p1->px + (r->first_y - data->p1->py) / tan(ray_a);
	r->x_step = r->y_step / tan(ray_a);
}

void	dda_h_2(t_dda *r, t_cub *data)
{
	while (r->max_iter < 100)
	{
		r->map_x = (int)r->first_x / SCALE_BLOCK;
		r->map_y = (int)r->first_y / SCALE_BLOCK;
		if (r->map_x < 0 || r->map_x >= data->map->width
			|| r->map_y < 0 || r->map_y >= data->map->height)
			break ;
		if (data->map->map[r->map_y][r->map_x] == '1')
		{
			r->hit = 1;
			break ;
		}
		r->first_x = r->first_x + r->x_step;
		r->first_y = r->first_y + r->y_step;
		r->max_iter++;
	}
}

void	dda_v_1(t_dda *r, t_cub *data, float ray_a)
{
	if (cos(ray_a) > 0.0001)
	{
		r->first_x = floor(data->p1->px / SCALE_BLOCK)
			* SCALE_BLOCK + SCALE_BLOCK;
		r->x_step = SCALE_BLOCK;
	}
	else
	{
		r->first_x = floor(data->p1->px / SCALE_BLOCK) * SCALE_BLOCK - 0.0001;
		r->x_step = -SCALE_BLOCK;
	}
	r->first_y = data->p1->py + (r->first_x - data->p1->px) * tan(ray_a);
	r->y_step = r->x_step * tan(ray_a);
}

void	dda_v_2(t_dda *r, t_cub *data)
{
	while (r->max_iter < 100)
	{
		r->map_x = (int)r->first_x / SCALE_BLOCK;
		r->map_y = (int)r->first_y / SCALE_BLOCK;
		if (r->map_x < 0 || r->map_x >= data->map->width
			|| r->map_y < 0 || r->map_y >= data->map->height)
			break ;
		if (data->map->map[r->map_y][r->map_x] == '1')
		{
			r->hit = 1;
			break ;
		}
		r->first_x = r->first_x + r->x_step;
		r->first_y = r->first_y + r->y_step;
		r->max_iter++;
	}
}
