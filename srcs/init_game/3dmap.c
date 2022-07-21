/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dmap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:07 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 16:16:59 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

unsigned int	get_pixel(t_pict_dt *img, float x, float y, int psh)
{
	unsigned int	ax;
	unsigned int	ay;

	ay = SCALE * (y - (WIN_Y / 2 - psh / 2)) / psh;
	ax = SCALE * (x / SCALE - (float)(int)(x / SCALE));
	return (*(unsigned *)(img->addr + \
	(ay * img->line_l + ax * (img->bpp / 8))));
}

void	draw_pict_wall(t_data data, int pix, int y, int psh)
{
	if (data.ray->s_x == 1)
	{
		if (data.ray->s == 'n')
			my_mlx_pixel_put(data.mlx, pix, y, \
			get_pixel(data.pict->no_wall, data.ray->x, y, psh));
		else
			my_mlx_pixel_put(data.mlx, pix, y, \
			get_pixel(data.pict->so_wall, data.ray->x, y, psh));
	}
	else
	{
		if (data.ray->s == 'w')
			my_mlx_pixel_put(data.mlx, pix, y, \
			get_pixel(data.pict->we_wall, data.ray->y, y, psh));
		else
			my_mlx_pixel_put(data.mlx, pix, y, \
			get_pixel(data.pict->ea_wall, data.ray->y, y, psh));
	}
}

void	draw3d_wall(t_data data, int pix, int y, int psh)
{
	if (y <= (WIN_Y / 2 - psh / 2))
		my_mlx_pixel_put(data.mlx, pix, y, data.pict->ceiling);
	else if (y >= WIN_Y / 2 + psh / 2)
		my_mlx_pixel_put(data.mlx, pix, y, data.pict->floor);
	else
	{
		if (data.ray->door == 1)
			my_mlx_pixel_put(data.mlx, pix, y, \
			get_pixel(data.pict->door, data.ray->y, y, psh));
		else if (data.ray->door == 2)
			my_mlx_pixel_put(data.mlx, pix, y, \
			get_pixel(data.pict->door, data.ray->x, y, psh));
		else
			draw_pict_wall(data, pix, y, psh);
	}
}

void	map3d_draw(t_data data, int pix)
{
	int	psh;
	int	line;
	int	y;

	psh = fabsf(SCALE / data.ray->len_ray * data.proj_plane_dist);
	line = psh / 2;
	y = 0;
	while (y < WIN_Y)
		draw3d_wall(data, pix, y++, psh);
}
