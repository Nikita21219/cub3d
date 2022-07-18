#include "../../includes/cub3D.h"

// void	draw_sprites(t_data *data)
// {
// 	t_sprite	*sprite;
// 	int			sprite_screen_size;
// 	int			i;
// 	int			j;

// 	sprite = data->sprite;
// 	sprite->len = sqrt(powf((int)data->pl->x - fabsf(sprite->x), 2.0) \
// 		+ powf((int)data->pl->y - fabsf(sprite->y), 2.0));
// 	sprite_screen_size = fabsf(SCALE / sprite->len * data->proj_plane_dist);
// 	if (sprite_screen_size > 1000)
// 		sprite_screen_size = 1000;
// 	i = -1;
// 	while (++i < sprite_screen_size)
// 	{
// 		if (sprite->x + i < 0 || sprite->x + i >= WIN_X)
// 			continue ;
// 		j = -1;
// 		while (++j < sprite_screen_size)
// 		{
// 		    if (sprite->y + j < 0 || sprite->y + j >= WIN_Y)
// 				continue;
// 			my_mlx_pixel_put(data->mlx, sprite->x + i, sprite->y + j + WIN_Y / 2, 000000);
// 		}
// 	}
// 	data->sprite = NULL;
// }

unsigned int	get_color(t_pict_dt *img, float x, float y)
{
	return (*(unsigned *)(img->addr + ((int)y * img->line_l + (int)x * (img->bpp / 8))));
}

void	draw_sprite(t_data *data, t_sprite *sprite)
{
	size_t	i;
	size_t	j;
	size_t	sprite_screen_size;
	int 	h_offset;
	int 	v_offset;
	void	*img;
	float	prop;
	unsigned int	pix_color;

	sprite_screen_size = WIN_Y / sprite->len;
	h_offset = sprite->dx - sprite_screen_size / 2;
	v_offset = WIN_Y / 2;
	i = -1;
	prop = (float)SCALE / (float)sprite_screen_size;
	while (++i < sprite_screen_size)
	{
		j = -1;
		while (++j < sprite_screen_size)
		{
			if (sprite->pict_num == 1)
				img = data->pict->sprite1;
			else
				img = data->pict->sprite2;
			pix_color = get_color(img, i * prop, j * prop);
			if (pix_color == 4278190080)
				continue ;
			my_mlx_pixel_put(data->mlx, h_offset + i, v_offset + j, pix_color);
		}
	}
}
