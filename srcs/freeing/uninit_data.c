/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uninit_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:58:31 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/18 17:00:14 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	last_free_uninit_data(t_cub *data)
{
	free(data->envx);
	free(data->p1);
	free(data->map->floor);
	free(data->map->sky);
	free(data->map);
	free(data);
}
