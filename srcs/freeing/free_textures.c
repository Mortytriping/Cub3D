/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:32:31 by apouesse          #+#    #+#             */
/*   Updated: 2025/04/05 16:32:32 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_textures(t_map *map)
{
	if (map->tex_no)
	{
		free(map->tex_no);
		map->tex_no = NULL;
	}
	if (map->tex_so)
	{
		free(map->tex_so);
		map->tex_so = NULL;
	}
	if (map->tex_we)
	{
		free(map->tex_we);
		map->tex_we = NULL;
	}
	if (map->tex_ea)
	{
		free(map->tex_ea);
		map->tex_ea = NULL;
	}
}
