/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:28:34 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/18 12:14:32 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data_extension2(t_cub *data)
{
	data->map->floor = malloc(sizeof(t_colors));
	if (!data->map->floor)
	{
		free(data->envx);
		free(data->p1);
		free(data->map);
		free(data);
		err_msg("error: malloc fatal fail at init_data.c!\n");
		exit (1);
	}
	data->map->sky = malloc(sizeof(t_colors));
	if (!data->map->sky)
	{
		free(data->envx);
		free(data->p1);
		free(data->map->floor);
		free(data->map);
		free(data);
		err_msg("error: malloc fatal fail at init_data.c!\n");
		exit (1);
	}
}

void	init_data_extension(t_cub *data)
{
	data->p1 = malloc(sizeof(t_player));
	if (!data->p1)
	{
		free(data);
		free(data->envx);
		err_msg("error: malloc fatal fail at init_data.c!\n");
		exit (1);
	}
	init_player(data);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		free(data);
		free(data->envx);
		free(data->p1);
		err_msg("error: malloc fatal fail at init_data.c!\n");
		exit (1);
	}
	init_data_extension2(data);
	data->active_img = 0;
}

t_cub	*init_data(void)
{
	t_cub	*data;

	data = malloc(sizeof(t_cub));
	if (!data)
	{
		err_msg("error: malloc fatal fail at init_data.c!\n");
		exit (1);
	}
	data->envx = malloc(sizeof(t_envx));
	if (!data->envx)
	{
		free(data);
		err_msg("error: malloc fatal fail at init_data.c!\n");
		exit (1);
	}
	init_data_extension(data);
	return (data);
}
