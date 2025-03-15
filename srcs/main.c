/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:29:11 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/15 19:28:48 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	*data;

	(void)av;
	(void)ac;
	data = init_data();
	// parsing(av);
	data->envx->mlx = mlx_init();
	init_win_img(data);
	mlx_hook(data->envx->mlx_win, 17, 0, close_win, data->envx);
	mlx_loop(data->envx->mlx);
	end_mlx(data);
	return (0);
}
