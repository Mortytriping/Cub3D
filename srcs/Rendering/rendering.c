/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:57:52 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/17 16:41:17 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render_next_frame(t_cub *data)
{
	raycaster(data);
	mlx_put_image_to_window(data->envx->mlx, data->envx->mlx_win,
		data->img[data->active_img].img, 0, 0);
	data->active_img = (data->active_img + 1) % 2;
	return (0);
}
