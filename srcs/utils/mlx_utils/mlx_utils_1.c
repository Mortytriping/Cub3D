/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:16:10 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 17:28:55 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

bool	init_img(t_cub *data, int img)
{
	data->img[img].img = mlx_new_image(data->envx->mlx, WIN_W, WIN_H);
	if (!data->img[img].img)
	{
		mlx_clear_window(data->envx->mlx, data->envx->mlx_win);
		mlx_destroy_window(data->envx->mlx, data->envx->mlx_win);
		mlx_destroy_display(data->envx->mlx);
		free(data->envx->mlx);
		last_free_uninit_data(data);
		err_msg("Fatal error on mlx\n");
		return (false);
	}
	data->img[img].addr = mlx_get_data_addr(data->img[img].img,
			&data->img[img].bits_per_pixel,
			&data->img[img].line_length, &data->img[img].endian);
	if (!data->img[img].addr)
	{
		mlx_clear_window(data->envx->mlx, data->envx->mlx_win);
		mlx_destroy_window(data->envx->mlx, data->envx->mlx_win);
		mlx_destroy_display(data->envx->mlx);
		free(data->envx->mlx);
		last_free_uninit_data(data);
		err_msg("Fatal error on mlx\n");
		return (false);
	}
	return (true);
}

bool	init_win_img(t_cub *data)
{
	data->envx->mlx_win = mlx_new_window(data->envx->mlx,
			WIN_W, WIN_H, "Cub3d");
	if (!data->envx->mlx_win)
	{
		mlx_destroy_display(data->envx->mlx);
		free(data->envx->mlx);
		last_free_uninit_data(data);
		err_msg("Fatal error on mlx\n");
		return (false);
	}
	if (init_img(data, 0) == false)
		return (false);
	if (init_img(data, 1) == false)
		return (mlx_destroy_image(data->envx->mlx, data->img[0].img), false);
	mlx_put_image_to_window(data->envx->mlx, data->envx->mlx_win,
		data->img[data->active_img].img, 0, 0);
	return (true);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
		return ;
	dst = mlx->addr + (y * mlx->line_length + x *(mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	free_last_er(t_cub *data)
{
	mlx_clear_window(data->envx->mlx, data->envx->mlx_win);
	mlx_destroy_window(data->envx->mlx, data->envx->mlx_win);
	mlx_destroy_display(data->envx->mlx);
	free_textures(data->map);
	free_array(data->map->map);
	free(data->envx->mlx);
	last_free_uninit_data(data);
}

void	end_mlx(t_cub *data)
{
	mlx_destroy_image(data->envx->mlx, data->img[0].img);
	mlx_destroy_image(data->envx->mlx, data->img[1].img);
	mlx_destroy_image(data->envx->mlx, data->textures[0].img);
	mlx_destroy_image(data->envx->mlx, data->textures[1].img);
	mlx_destroy_image(data->envx->mlx, data->textures[2].img);
	mlx_destroy_image(data->envx->mlx, data->textures[3].img);
	mlx_clear_window(data->envx->mlx, data->envx->mlx_win);
	mlx_destroy_window(data->envx->mlx, data->envx->mlx_win);
	mlx_destroy_display(data->envx->mlx);
	free_textures(data->map);
	free_array(data->map->map);
	free(data->envx->mlx);
	last_free_uninit_data(data);
}
