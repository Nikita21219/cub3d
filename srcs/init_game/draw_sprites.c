#include "../../includes/cub3D.h"

void	draw_sprites(t_data *data)
{
	int		i;
	int		j;
	int		sprite_screen_size;
	int		sprite_dist;
	float	sprite_dir;
	int 	h_offset;
	int 	v_offset;

	sprite_dir = atan2(data->sprite->y - data->pl->y / SCALE, data->sprite->x - data->pl->x / SCALE);
	// printf("sprite_dir = %f\ndata->pl->dir = %f\n", sprite_dir, data->pl->dir);
    while (sprite_dir - data->pl->dir > M_PI)
		sprite_dir -= 2 * M_PI;
    while (sprite_dir - data->pl->dir < -M_PI)
		sprite_dir += 2 * M_PI;
	sprite_dist = sqrt(pow((data->pl->x / SCALE) - (data->sprite->x), 2) + pow(data->pl->y / SCALE - (data->sprite->y), 2));
	sprite_screen_size = WIN_Y / sprite_dist;
	h_offset = (sprite_dir - data->pl->dir) / FOV * (WIN_X / 2) + (WIN_X / 2) / 2 - 200 / 2;
    v_offset = WIN_Y / 2 - sprite_screen_size / 2;
	i = -1;
	while (++i < sprite_screen_size)
	{
        if (h_offset + i < 0 || h_offset + i >= WIN_X / 2)
			continue ;
		j = -1;
		while (++j < sprite_screen_size)
		{
            if (v_offset + j < 0 || v_offset + j >= WIN_Y)
				continue;
			my_mlx_pixel_put(data->mlx, WIN_X / 2 + h_offset + i, v_offset + j, 000000);
		}
	}
}
