/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:59:00 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/17 15:57:34 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	keyboard_events(int keycode, t_envx *envx)
{
	if (keycode == 65307)
		mlx_loop_end(envx->mlx);
	return (0);
}
