/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:16:10 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/15 19:56:17 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_win_img(t_cub *data)
{
	data->envx->mlx_win = mlx_new_window(data->envx->mlx, 1920, 1080, "Cub3d");
	data->img.img = mlx_new_image(data->envx->mlx, 1920, 1080);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	// my_mlx_pixel_put(&data->img, 5, 5, 0x00FF0000);
	//	game_cub3d_exec;
	mlx_put_image_to_window(data->envx->mlx, data->envx->mlx_win, data->img.img, 0, 0);
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
	mlx_destroy_image(data->envx->mlx, data->img.img);
	mlx_clear_window(data->envx->mlx, data->envx->mlx_win);
	mlx_destroy_window(data->envx->mlx, data->envx->mlx_win);
	mlx_destroy_display(data->envx->mlx);
	//free all here
	free(data->envx->mlx);
	last_free_uninit_data(data);
}
