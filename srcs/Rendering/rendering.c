/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:57:52 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/18 16:06:22 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	black_screen(t_mlx *img)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while(x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			my_mlx_pixel_put(img, x, y, 0);
			y++;
		}
		x++;
	}
}

void	draw_square(t_cub *data, int x, int y, int size, int color)
{
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(&data->img[data->active_img], x + i, y, color);
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(&data->img[data->active_img], x, y + i, color);
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(&data->img[data->active_img], x + size, y + i, color);
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(&data->img[data->active_img], x + i, y + size, color);	
}

int	render_next_frame(t_cub *data)
{
	raycaster(data);
	moove_player(data);
	draw_square(data, data->p1->px, data->p1->py, 5, 0x00FF00);
	mlx_put_image_to_window(data->envx->mlx, data->envx->mlx_win,
		data->img[data->active_img].img, 0, 0);
	data->active_img = (data->active_img + 1) % 2;
	black_screen(&data->img[data->active_img]);
	return (0);
}
