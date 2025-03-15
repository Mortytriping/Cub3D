/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:52:36 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/15 12:38:37 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBD3D_H
# define CUBD3D_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct s_colors
{
	int	mur;
} t_colors;

typedef struct s_player
{
	float	px;
	float	py;
} t_player;

#endif