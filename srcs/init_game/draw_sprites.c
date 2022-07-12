#include "../../includes/cub3D.h"

void	draw_sprites(t_data *data)
{
	t_sprite	*sprite;
	int			sprite_screen_size;
	int			i;
	int			j;

	sprite = data->sprite;
	sprite->len = sqrt(powf((int)data->pl->x - fabsf(sprite->x), 2.0) \
		+ powf((int)data->pl->y - fabsf(sprite->y), 2.0));
	sprite_screen_size = fabsf(SCALE / sprite->len * data->proj_plane_dist);
	if (sprite_screen_size > 1000)
		sprite_screen_size = 1000;
	i = -1;
	while (++i < sprite_screen_size)
	{
		if (sprite->x + i < 0 || sprite->x + i >= WIN_X)
			continue ;
		j = -1;
		while (++j < sprite_screen_size)
		{
		    if (sprite->y + j < 0 || sprite->y + j >= WIN_Y)
				continue;
			my_mlx_pixel_put(data->mlx, sprite->x + i, sprite->y + j + WIN_Y / 2, 000000);
		}
	}
	data->sprite = NULL;
}
