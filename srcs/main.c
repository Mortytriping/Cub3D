/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:29:11 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/03 17:10:54 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_texture(t_cub *data, char *path, t_texture *texture)
{
	texture->img = NULL;
	texture->addr = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->bpp = 0;
	texture->line_length = 0;
	texture->endian = 0;
    texture->img = mlx_xpm_file_to_image(data->envx->mlx, path, &texture->width, &texture->height);
	printf("path = %s, width = %d, height = %d\n", path, texture->width, texture->height);
    if (!texture->img)
    {
        ft_putstr_fd("Error\nFailed to load texture: ", 2);
        ft_putstr_fd(path, 2);
        ft_putstr_fd("\n", 2);
        exit(EXIT_FAILURE);
    }
    texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, &texture->line_length, &texture->endian);
    if (!texture->addr)
    {
        ft_putstr_fd("Error\nFailed to get texture data address for: ", 2);
        ft_putstr_fd(path, 2);
        ft_putstr_fd("\n", 2);
        exit(EXIT_FAILURE);
    }
}

void	init_texture(t_cub *data)
{
    load_texture(data, data->map->tex_no, &data->textures[0]); // Texture Nord
    load_texture(data, data->map->tex_so, &data->textures[1]); // Texture Sud
    load_texture(data, data->map->tex_ea, &data->textures[2]);  // Texture Est
    load_texture(data, data->map->tex_we, &data->textures[3]);  // Texture Ouest
}

int	main(int ac, char **av)
{
	t_cub	*data;

	(void)av;
	(void)ac;
	data = init_data();
	if (!parsing(av, ac, data))
		return (last_free_uninit_data(data), 1);
	printf("w = %d, h = %d\n", data->map->height, data->map->width);
	data->envx->mlx = mlx_init();
	if (!data->envx->mlx)
		return (err_msg("Fatal error on mlx"), last_free_uninit_data(data), 1);
	init_win_img(data); //creation image[0 et 1] avec img[0] sur la window
	init_texture(data);
	mlx_hook(data->envx->mlx_win, 2, 1L<<0, key_press, data);
	mlx_hook(data->envx->mlx_win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_loop_hook(data->envx->mlx, render_next_frame, data);
	mlx_hook(data->envx->mlx_win, 17, 0, close_win, data->envx);
	mlx_loop(data->envx->mlx);
	end_mlx(data);
	return (0);
}
