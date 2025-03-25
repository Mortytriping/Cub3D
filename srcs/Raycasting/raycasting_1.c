/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:40:22 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/25 15:56:19 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ray_touch_wall(t_cub *data, int px, int py)
{
	int x;
	int y;
	x = px / SCALE_BLOCK;
	y = py / SCALE_BLOCK;
	if (x > data->map->width - 1 || y > data->map->height - 1 || y < 0 || x < 0)
		return (true);
	if (data->map->map[y][x] == '1')
		return (true);
	return (false);
}

float	clc_dist(float x, float y)
{
	return (sqrt((x * x) + (y * y)));
}

float	distance(t_cub *data, float ray_x, float ray_y)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = ray_x - data->p1->px;
	delta_y = ray_y - data->p1->py;
	angle = atan2(delta_y, delta_x) - data->p1->pov;
	fix_dist = clc_dist(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

void	draw_rays(t_cub *data, float start_x, int i)
{
	float	sin_pov;
	float	cos_pov;
	float	ray_y;
	float	ray_x;
	float	dist;
	float	height;
	int		start_y;
	int 	end;

	ray_x = data->p1->px;
	ray_y = data->p1->py;
	cos_pov = cos(start_x);
	sin_pov = sin(start_x);
	while (!ray_touch_wall(data, ray_x, ray_y) && (ray_x < WIN_W && ray_y < WIN_H)) //a remplacer par un DDA algo pour otpi (force a nous);
	{
		my_mlx_pixel_put(&data->img[data->active_img], ray_x, ray_y, create_trgb(255, 255, 0, 0));
		ray_x += cos_pov;
		ray_y += sin_pov;
	}
	(void)i; 
	dist = distance(data, ray_x, ray_y);
	height = (SCALE_BLOCK / dist) * (WIN_W / 2);
	start_y = (WIN_H - height) / 2;
	end = start_y + height;
	while (start_y < end)
	{
		my_mlx_pixel_put(&data->img[data->active_img], i, start_y, create_trgb(255, 0, 0, 255));
		start_y++;
	}
}

// void	dda_checker(t_cub *data)
// {
// 	int	r;
// 	int mx;
// 	int my;
// 	int mp;
// 	int dof;
// 	float rx;
// 	float ry;
// 	float ra;
// 	float xo;
// 	float yo;


// 	ra = data->p1->pov;
// 	for (r=0;r<1;r++)
// 	{
// 		dof = 0;
// 		float aTan = -1/tan(ra);
// 		if (ra>PI){ ry=(((int)data->p1->py>>6)<<6)-0.0001; rx = (data->p1->px-ry)*aTan+data->p1->px; yo=-64; xo = -yo*aTan;}//looking up
// 		if (ra<PI){ ry=(((int)data->p1->py>>6)<<6)+64;     rx = (data->p1->px-ry)*aTan+data->p1->px; yo= 64; xo = -yo*aTan;}//looking down
// 		if (ra==0 || ra==PI) {rx=data->p1->px; ry=data->p1->py; dof = 8;}
// 		while (dof<8)
// 		{
// 			mx=(int) (rx)>>6; my(int) (ry)>>6; mp=my*mapX+mx;
// 			if (mp<mapX*mapY && map[mp]==1) { dof=8;}
// 			else {rx+=xo; ry+=yo; dof+=1;}
// 		}
// }

void	raycaster(t_cub *data)
{
	(void)data;
}
