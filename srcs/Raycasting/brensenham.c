/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brensenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:15:47 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/27 17:49:52 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_bresenham(t_point p1, t_point p2, t_cub *data, int color)
{
	t_bresenham	vars;

	vars.y = p1.y;
	vars.x = p1.x;
	vars.diff_x = p2.x - p1.x;
	vars.diff_y = p2.y - p1.y;
	if (vars.diff_x > 0)
		vars.step_x = 1;
	else
		vars.step_x = -1;
	if (vars.diff_y > 0)
		vars.step_y = 1;
	else
		vars.step_y = -1;
	vars.diff_x = abs(vars.diff_x);
	vars.diff_y = abs(vars.diff_y);
	if (vars.diff_x > vars.diff_y)
	{
		vars.error = 2 * vars.diff_y - vars.diff_x;
		while (vars.x != p2.x || vars.y != p2.y)
		{
			my_mlx_pixel_put(&data->img[data->active_img], vars.x, vars.y, color);
			if (vars.error < 0)
				vars.error += 2 * vars.diff_y;
			else
			{
				vars.error += (2 * vars.diff_y) - (2 * vars.diff_x);
				vars.y+= vars.step_y;
			}
			vars.x+= vars.step_x;
		}
	}
	else
	{
		vars.error = 2 * vars.diff_x - vars.diff_y;
		while (vars.x != p2.x || vars.y != p2.y)
		{
			my_mlx_pixel_put(&data->img[data->active_img], vars.x, vars.y, color);
			if (vars.error < 0)
				vars.error += 2 * vars.diff_x;
			else
			{
				vars.error += (2 * vars.diff_x) - (2 * vars.diff_y);
				vars.x+= vars.step_x;
			}
			vars.y+= vars.step_y;
		}
	}
}
