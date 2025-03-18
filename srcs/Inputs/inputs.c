/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:59:00 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/18 16:08:13 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	keyboard_events(int keycode, t_cub *data)
{
	if (keycode == 65307)
		mlx_loop_end(data->envx->mlx);
	return (0);
}

int	key_press(int keycode, t_cub *data)
{
	if (keycode == W)
		data->p1->moove_up = true;
	if (keycode == A)
		data->p1->moove_left = true;
	if (keycode == S)
		data->p1->moove_down = true;
	if (keycode == D)
		data->p1->moove_right = true;
	if (keycode == 65307)
		mlx_loop_end(data->envx->mlx);
	return (0);
}

int	key_release(int keycode, t_cub *data)
{
	// printf("\n%ddasd\n", keycode);
	if (keycode == W)
		data->p1->moove_up = false;
	if (keycode == A)
		data->p1->moove_left = false;
	if (keycode == S)
		data->p1->moove_down = false;
	if (keycode == D)
		data->p1->moove_right = false;
	return (0);
}
