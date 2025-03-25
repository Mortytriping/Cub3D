/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:29:11 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/25 15:51:55 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	*data;

	(void)av;
	(void)ac;
	data = init_data();
	// data->map->map = testing_map(data);
	
	if(!parsing(av, ac, data))
		return (last_free_uninit_data(data), 1);
	printf("w = %d, h = %d\n", data->map->height, data->map->width);
	data->envx->mlx = mlx_init();
	if (!data->envx->mlx)
		return (err_msg("Fatal error on mlx"), last_free_uninit_data(data), 1);
	init_win_img(data); //creation image[0 et 1] avec img[0] sur la window
	mlx_hook(data->envx->mlx_win, 2, 1L<<0, key_press, data);
	mlx_hook(data->envx->mlx_win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_loop_hook(data->envx->mlx, render_next_frame, data);
	mlx_hook(data->envx->mlx_win, 17, 0, close_win, data->envx);
	mlx_loop(data->envx->mlx);
	end_mlx(data);
	return (0);
}
