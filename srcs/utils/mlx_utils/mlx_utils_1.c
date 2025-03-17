/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:16:10 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/17 15:25:37 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_win_img(t_cub *data)
{
	data->envx->mlx_win = mlx_new_window(data->envx->mlx, 1920, 1080, "Cub3d");
	data->img[data->active_img].img = mlx_new_image(data->envx->mlx, 1920, 1080);
	data->img[data->active_img].addr = mlx_get_data_addr(data->img[data->active_img].img,
		&data->img[data->active_img].bits_per_pixel,
		&data->img[data->active_img].line_length, &data->img[data->active_img].endian);
	data->img[1].img = mlx_new_image(data->envx->mlx, 1920, 1080);
	data->img[1].addr = mlx_get_data_addr(data->img[1].img,
		&data->img[1].bits_per_pixel,
		&data->img[1].line_length, &data->img[1].endian);
	mlx_put_image_to_window(data->envx->mlx, data->envx->mlx_win,
	data->img[data->active_img].img, 0, 0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_win(t_envx *env)
{
	mlx_loop_end(env->mlx);
	return (0);
}

void	end_mlx(t_cub *data)
{
	mlx_destroy_image(data->envx->mlx, data->img[0].img);
	mlx_destroy_image(data->envx->mlx, data->img[1].img);
	mlx_clear_window(data->envx->mlx, data->envx->mlx_win);
	mlx_destroy_window(data->envx->mlx, data->envx->mlx_win);
	mlx_destroy_display(data->envx->mlx);
	//free all here
	free(data->envx->mlx);
	last_free_uninit_data(data);
}
