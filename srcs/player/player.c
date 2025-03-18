/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:50:29 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/18 12:35:56 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_cub *data)
{
	data->p1->px = WIN_W / 2;
	data->p1->py = WIN_H / 2;
	data->p1->moove_up = false;
	data->p1->moove_down = false;
	data->p1->moove_right = false;
	data->p1->moove_left = false;
}

void	moove_player(t_cub *data)
{
	if (data->p1->moove_up)
		data->p1->py -= SPEED;
	if (data->p1->moove_down)
		data->p1->py += SPEED;
	if (data->p1->moove_right)
		data->p1->px += SPEED;
	if (data->p1->moove_left)
		data->p1->px -= SPEED;
}
