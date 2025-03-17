/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:35:38 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/17 14:24:18 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	trunc_error_rgb(int *t, int *r, int *g, int *b)
{
	if (*t < 0)
		*t = 0;
	if (*r < 0)
		*r = 0;
	if (*r > 255)
		*r = 255;
	if (*g < 0)
		*g = 0;
	if (*g > 255)
		*g = 255;
	if (b < 0)
		*b = 0;
	if (*b > 255)
		*b = 255;
}

int	create_trgb(int t, int r, int g, int b)
{
	trunc_error_rgb(&t, &r, &g, &b);
	return (t << 24 | r << 16 | g << 8 | b);
}
