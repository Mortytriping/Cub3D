/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:41:30 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 16:13:16 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	clc_dist(float x, float y)
{
	return (sqrt((x * x) + (y * y)));
}

float	distance(t_cub *data, float ray_x, float ray_y, float ray_a)
{
	float	delta_x;
	float	delta_y;
	float	fix_dist;

	delta_x = ray_x - data->p1->px;
	delta_y = ray_y - data->p1->py;
	fix_dist = clc_dist(delta_x, delta_y) * cos(ray_a - data->p1->pov);
	if (fix_dist < 1.0)
		fix_dist = 1.0;
	return (fix_dist);
}

void	err_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free (array);
}
