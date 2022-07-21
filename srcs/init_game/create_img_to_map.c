/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_to_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:15 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:16 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_2dmap(t_data data)
{
	int	x;
	int	y;

	y = 0;
	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x])
		{
			if (data.map[y][x] == '1')
				draw_block(data.mlx, x * SCALE / 6, y * SCALE / 6, 0x000000);
			if (data.map[y][x] == '0' || data.map[y][x] == 'N' || \
			data.map[y][x] == 'S' || data.map[y][x] == 'E' \
			|| data.map[y][x] == 'W' || data.map[y][x] == 'e')
				draw_block(data.mlx, x * SCALE / 6, y * SCALE / 6, 0xFFFFFF);
			if (data.map[y][x] == 'd')
				draw_block(data.mlx, x * SCALE / 6, y * SCALE / 6, 0xff8c21);
			x++;
		}
		y++;
	}
	draw_square(&data, (int)data.pl->x / 6, (int)data.pl->y / 6);
}

void	sprite_data(t_data *data)
{
	t_sprite	*sprite;

	sprite = data->sprite;
	while (sprite)
	{
		sprite->dir = atan2((data->pl->y) - (sprite->y * SCALE \
		+ SCALE / 2), (sprite->x * SCALE + SCALE / 2) - (data->pl->x));
		while (sprite->dir - data->pl->dir > M_PI)
			sprite->dir -= 2 * M_PI;
		while (sprite->dir - data->pl->dir < -M_PI)
			sprite->dir += 2 * M_PI;
		sprite->len = sqrt(pow((data->pl->x) - (sprite->x * SCALE + SCALE \
		/ 2), 2) + pow(data->pl->y - (sprite->y * SCALE + SCALE / 2), 2));
		sprite = sprite->next;
	}
}

void	write_rays(t_data *data)
{
	int			pix;
	t_sprite	*sprite;

	pix = 0;
	while (data->pl->start >= data->pl->end)
	{
		rays(data, data->pl->start);
		data->n_ray[pix] = data->ray->len_ray;
		data->ray->len_ray *= cos(data->pl->start - data->pl->dir);
		map3d_draw(*data, pix);
		sprite = data->sprite;
		while (sprite)
		{
			if (sprite->dir > data->pl->start - ((FOV \
			* M_PI / 180) / WIN_X) && sprite->dir < data->pl->start)
				sprite->dx = pix;
			sprite = sprite->next;
		}
		data->pl->start -= ((FOV * M_PI / 180) / WIN_X);
		pix++;
	}
}

void	draw_map(t_data *data)
{
	t_sprite	*sprite;

	data->mlx->img = mlx_new_image(data->mlx->mlx, WIN_X, WIN_Y);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, \
	&data->mlx->bpp, &data->mlx->line_l, &data->mlx->endian);
	data->pl->start = data->pl->dir + ((FOV / 2) * M_PI / 180);
	data->pl->end = data->pl->dir - ((FOV / 2) * M_PI / 180);
	sprite_data(data);
	write_rays(data);
	sprite = data->sprite;
	sort_sprites(sprite);
	while (sprite)
	{
		if (sprite->dx != 0)
			draw_sprite(data, sprite, data->n_ray);
		sprite->dx = 0;
		sprite = sprite->next;
	}
	draw_2dmap(*data);
	mlx_put_image_to_window(data->mlx->mlx, \
		data->mlx->win, data->mlx->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
}
