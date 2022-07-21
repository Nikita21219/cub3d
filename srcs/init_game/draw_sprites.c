#include "../../includes/cub3D.h"

unsigned int	get_color(t_pict_dt *img, float x, float y)
{
	return (*(unsigned *)(img->addr + ((int)y \
	* img->line_l + (int)x * (img->bpp / 8))));
}

void	draw_sprite(t_data *data, t_sprite *sprite, float *len_wall)
{
	size_t			i;
	size_t			j;
	size_t			sprite_screen_size;
	int 			h_offset;
	int 			v_offset;
	void			*img;
	float			prop;
	unsigned int	pix_color;

	sprite_screen_size = WIN_Y / (sprite->len / SCALE);
	h_offset = sprite->dx - sprite_screen_size / 2;
	v_offset = WIN_Y / 2;
	i = -1;
	prop = (float)SCALE / (float)sprite_screen_size;
	while (++i < sprite_screen_size)
	{
		j = -1;
		while (++j < sprite_screen_size)
		{
			if (data->sprite->pict_num == 1)
				img = data->pict->sprite1;
			else
				img = data->pict->sprite2;
			pix_color = get_color(img, i * prop, j * prop);
			if (pix_color == 4278190080 || len_wall[h_offset + i] < sprite->len)
				continue ;
			my_mlx_pixel_put(data->mlx, h_offset + i, v_offset + j, pix_color);
		}
	}
}
