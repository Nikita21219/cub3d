#include "../../includes/cub3D.h"

void	draw_sprites(t_data *data)
{
	t_sprite	*spr;
	int			psh;
	int			x;
	int			y;

	if (!data->sprite)
		return ;
	spr = data->sprite;
	psh = fabsf(SCALE / spr->len * data->proj_plane_dist) / 4;
	while (spr)
	{
		x = psh;
		while (x)
		{
			y = psh;
			while (y)
			{
				my_mlx_pixel_put(data->mlx, spr->x, spr->y, 0X000000);
				y--;
			}
			x--;
		}
		data->sprite = data->sprite->next;
		free(spr);
		spr = data->sprite;
	}
	data->sprite = NULL;
}
