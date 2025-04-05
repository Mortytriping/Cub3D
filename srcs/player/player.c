/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:50:29 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 18:04:02 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_cub *data)
{
	data->p1->px = WIN_W / 2;
	data->p1->py = WIN_H / 2;
	data->p1->pov = RD * FOV;
	data->p1->moove_up = false;
	data->p1->moove_down = false;
	data->p1->moove_right = false;
	data->p1->moove_left = false;
}

void	moove_player2(t_cub *data, float cos_angle, float sin_angle)
{
	if (data->p1->moove_up)
	{
		data->p1->px += cos_angle * SPEED;
		data->p1->py += sin_angle * SPEED;
	}
	if (data->p1->moove_down)
	{
		data->p1->px -= cos_angle * SPEED;
		data->p1->py -= sin_angle * SPEED;
	}
	if (data->p1->moove_left)
	{
		data->p1->px += sin_angle * SPEED;
		data->p1->py -= cos_angle * SPEED;
	}
	if (data->p1->moove_right)
	{
		data->p1->px -= sin_angle * SPEED;
		data->p1->py += cos_angle * SPEED;
	}
}

void	moove_player(t_cub *data)
{
	float	rotate_speed;
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(data->p1->pov);
	sin_angle = sin(data->p1->pov);
	rotate_speed = 0.022;
	if (data->p1->rotate_left)
		data->p1->pov -= rotate_speed;
	if (data->p1->rotate_right)
		data->p1->pov += rotate_speed;
	if (data->p1->pov > (2 * PI))
		data->p1->pov = 0;
	if (data->p1->pov < 0)
		data->p1->pov = 2 * PI;
	moove_player2(data, cos_angle, sin_angle);
}
