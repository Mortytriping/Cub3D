/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:29:11 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/17 16:47:41 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void testing_map(t_cub *data)
{
	char *simulated_map[] = {
		"111111",
		"100001",
		"101101",
		"1000N1",
		"111111",
		NULL
	};
	data->map->map = simulated_map;
	data->map->floor->color = create_trgb(255, 0, 255, 0);
	data->map->sky->color = create_trgb(255, 50, 0, 255);
}

int	main(int ac, char **av)
{
	t_cub	*data;

	(void)av;
	(void)ac;
	data = init_data();
	testing_map(data);
	// parsing(av);
	data->envx->mlx = mlx_init();
	if (!data->envx->mlx)
		return (err_msg("fatal error on mlx\n"), last_free_uninit_data(data), 1);
	init_win_img(data); //creation image[0 et 1] avec img[0] sur la window
	mlx_key_hook(data->envx->mlx_win, keyboard_events, data->envx);
	mlx_loop_hook(data->envx->mlx, render_next_frame, data);
	mlx_hook(data->envx->mlx_win, 17, 0, close_win, data->envx);
	mlx_loop(data->envx->mlx);
	end_mlx(data);
	return (0);
}
