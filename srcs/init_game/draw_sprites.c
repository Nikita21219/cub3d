#include "../../includes/cub3D.h"

void	draw_sprites(t_data *data, int pix)
{
	t_sprite	*spr;
	int			psh;
	int			line;
	int			y;

	spr = data->sprite;
	if (!data->sprite || data->ray->len_ray < data->sprite->len)
	{
		while (spr)
		{
			data->sprite = data->sprite->next;
			free(spr);
			spr = data->sprite;
		}
		return ;
	}
	psh = fabsf(SCALE / spr->len * data->proj_plane_dist);
	line = psh / 2;
	y = WIN_Y / 2 - line;
	while (y <= WIN_Y / 2 + line)
		my_mlx_pixel_put(data->mlx, pix, y++, 0x000000);
	while (spr)
	{
		data->sprite = data->sprite->next;
		free(spr);
		spr = data->sprite;
	}
}
