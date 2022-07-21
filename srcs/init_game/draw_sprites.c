/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:20 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:21 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

unsigned int	get_color(t_pict_dt *img, float x, float y)
{
	return (*(unsigned *)(img->addr + ((int)y \
	* img->line_l + (int)x * (img->bpp / 8))));
}

int	pixel_sprite_start(t_sprite *sprite, float *prop)
{
	sprite->sprite_screen_size = WIN_Y / (sprite->len / SCALE);
	sprite->v_offset = WIN_Y / 2;
	sprite->h_offset = sprite->dx - sprite->sprite_screen_size / 2;
	*prop = (float)SCALE / (float)sprite->sprite_screen_size;
	return (-1);
}

void	draw_sprite(t_data *data, t_sprite *sprite, float *len_wall)
{
	size_t			i;
	size_t			j;
	float			prop;
	unsigned int	pix_color;
	void			*img;

	i = pixel_sprite_start(sprite, &prop);
	while (++i < sprite->sprite_screen_size)
	{
		j = -1;
		while (++j < sprite->sprite_screen_size)
		{
			if (data->sprite->pict_num == 1)
				img = data->pict->sprite1;
			else
				img = data->pict->sprite2;
			pix_color = get_color(img, i * prop, j * prop);
			if (pix_color == 4278190080 || sprite->h_offset + i > WIN_X \
			|| len_wall[sprite->h_offset + i] < sprite->len)
				continue ;
			my_mlx_pixel_put(data->mlx, sprite->h_offset + i, \
			sprite->v_offset + j, pix_color);
		}
	}
}
