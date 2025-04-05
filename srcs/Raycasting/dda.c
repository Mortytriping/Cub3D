/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:09:16 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 16:30:21 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dda_horizon(t_dda *r, t_cub *data, float ray_a)
{
	if (fabs((sin(ray_a))) > 0.0001)
	{
		dda_h_1(r, data, ray_a);
		dda_h_2(r, data);
		if (r->hit)
		{
			r->h_p.x = r->first_x;
			r->h_p.y = r->first_y;
			r->h_wall_size = distance(data, r->h_p.x, r->h_p.y, ray_a);
		}
		else
			r->h_wall_size = 1e30;
	}
	else
		r->h_wall_size = 1e30;
}

void	dda_vertical(t_dda *r, t_cub *data, float ray_a)
{
	r->max_iter = 0;
	r->hit = 0;
	if (fabs(cos(ray_a)) > 0.0001)
	{
		dda_v_1(r, data, ray_a);
		dda_v_2(r, data);
		if (r->hit)
		{
			r->v_p.x = r->first_x;
			r->v_p.y = r->first_y;
			r->v_wall_size = distance(data, r->v_p.x, r->v_p.y, ray_a);
		}
		else
			r->v_wall_size = 1e30;
	}
	else
		r->v_wall_size = 1e30;
}

void	dda_checker(t_cub *data, float ray_a, int x)
{
	t_dda	r;

	dda_horizon(&r, data, ray_a);
	dda_vertical(&r, data, ray_a);
	raycasting(data, r, x, ray_a);
}
