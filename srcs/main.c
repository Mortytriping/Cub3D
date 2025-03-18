/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:29:11 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/18 18:18:59 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char **testing_map(t_cub *data)
{
	char **simulated_map;

    simulated_map = malloc(sizeof(char *) * (9 + 1));
    if (!simulated_map)
        return (NULL);
    simulated_map[0] = strdup("111111111111");
    simulated_map[1] = strdup("100000000001");
    simulated_map[2] = strdup("100001000001");
    simulated_map[3] = strdup("100000000001");
    simulated_map[4] = strdup("100000000001");
    simulated_map[5] = strdup("101100000001");
    simulated_map[6] = strdup("100010000001");
	simulated_map[7] = strdup("100010000001");
	simulated_map[8] = strdup("1000N0000001");
    simulated_map[9] = strdup("111111111111");
    simulated_map[10] = NULL;
	data->map->map = simulated_map;
	data->map->height = 12;
	data->map->width = 9;
	data->map->floor->color = create_trgb(255, 0, 255, 0);
	data->map->sky->color = create_trgb(255, 50, 0, 255);
	return (simulated_map);
}

int	main(int ac, char **av)
{
	t_cub	*data;

	(void)av;
	(void)ac;
	data = init_data();
	data->map->map = testing_map(data);
	
	// if(!parsing(av, ac, data))
	// 	return (last_free_uninit_data(data), 1);
	data->envx->mlx = mlx_init();
	if (!data->envx->mlx)
		return (err_msg("fatal error on mlx\n"), last_free_uninit_data(data), 1);
	init_win_img(data); //creation image[0 et 1] avec img[0] sur la window
	mlx_hook(data->envx->mlx_win, 2, 1L<<0, key_press, data);
	mlx_hook(data->envx->mlx_win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_loop_hook(data->envx->mlx, render_next_frame, data);
	mlx_hook(data->envx->mlx_win, 17, 0, close_win, data->envx);
	mlx_loop(data->envx->mlx);
	end_mlx(data);
	return (0);
}
