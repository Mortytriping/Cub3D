/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:29:11 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 17:30:44 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	load_texture(t_cub *data, char *path, t_texture *texture)
{
	texture->img = NULL;
	texture->addr = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->bpp = 0;
	texture->line_length = 0;
	texture->endian = 0;
	texture->img = mlx_xpm_file_to_image(data->envx->mlx,
			path, &texture->width, &texture->height);
	if (!texture->img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (false);
	}
	texture->addr = mlx_get_data_addr(texture->img,
			&texture->bpp, &texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		ft_putstr_fd("Error\nFailed to get texture data address for: ", 2);
		ft_putstr_fd(path, 2);
		return (ft_putstr_fd("\n", 2), false);
	}
	return (true);
}

bool	init_texture(t_cub *data)
{
	if (load_texture(data, data->map->tex_no, &data->textures[0]) == false)
		return (false);
	if (load_texture(data, data->map->tex_so, &data->textures[1]) == false)
		return (mlx_destroy_image(data->envx->mlx, data->textures[0].img),
			false);
	if (load_texture(data, data->map->tex_ea, &data->textures[2]) == false)
		return (mlx_destroy_image(data->envx->mlx, data->textures[0].img),
			mlx_destroy_image(data->envx->mlx, data->textures[1].img), false);
	if (load_texture(data, data->map->tex_we, &data->textures[3]) == false)
		return (mlx_destroy_image(data->envx->mlx, data->textures[0].img),
			mlx_destroy_image(data->envx->mlx, data->textures[1].img),
			mlx_destroy_image(data->envx->mlx, data->textures[2].img), false);
	return (true);
}

int	main(int ac, char **av)
{
	t_cub	*data;

	data = init_data();
	if (!parsing(av, ac, data))
		return (last_free_uninit_data(data), 1);
	data->envx->mlx = mlx_init();
	if (!data->envx->mlx)
		return (err_msg("Fatal error on mlx"), last_free_uninit_data(data), 1);
	if (init_win_img(data) == false)
		return (free_last_er(data), err_msg("Fatal error on mlx"), 1);
	if (init_texture(data) == false)
		return (mlx_destroy_image(data->envx->mlx, data->img[0].img),
			mlx_destroy_image(data->envx->mlx, data->img[1].img),
			free_last_er(data), err_msg("Fatal error on textures..."), 1);
	mlx_hook(data->envx->mlx_win, 2, 1L << 0, key_press, data);
	mlx_hook(data->envx->mlx_win, KeyRelease, KeyReleaseMask,
		key_release, data);
	mlx_loop_hook(data->envx->mlx, render_next_frame, data);
	mlx_hook(data->envx->mlx_win, 17, 0, close_win, data->envx);
	mlx_loop(data->envx->mlx);
	end_mlx(data);
	return (0);
}
