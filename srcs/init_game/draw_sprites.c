#include "../../includes/cub3D.h"

void	draw_sprites(t_data *data)
{
	int	i;
	int	j;
	int	sprite_screen_size;
	int	sprite_dist;

	sprite_dist = sqrt(pow((data->pl->x / SCALE) - (data->sprite->x), 2) + pow(data->pl->y / SCALE - (data->sprite->y), 2));
	sprite_screen_size = WIN_Y / sprite_dist;
	i = -1;
	float sprite_dir = atan2(data->sprite->y - data->pl->y, data->sprite->x - data->pl->x);
	int h_offset = (sprite_dir - data->pl->dir) / FOV * (WIN_X / 2) + (WIN_X / 2) / 2 - 200 / 2;
    int v_offset = WIN_Y / 2 - sprite_screen_size / 2;
	while (++i < sprite_screen_size)
	{
		j = -1;
        if (h_offset + i < 0 || h_offset + i >= WIN_X / 2)
			continue ;
		while (++j < sprite_screen_size)
		{
            if (v_offset + j < 0 || v_offset + j >= WIN_Y)
				continue;
			my_mlx_pixel_put(data->mlx, WIN_X / 2 + h_offset + i, v_offset + j, 000000);
		}
	}

    // for (size_t i=0; i<sprite_screen_size; i++) {
    //     if (h_offset+i<0 || h_offset+i>=WIN_X/2) continue;
    //     for (size_t j=0; j<sprite_screen_size; j++) {
    //         if (v_offset+j<0 || v_offset+j>=WIN_Y) continue;
    //         fb.set_pixel(WIN_X/2 + h_offset+i, v_offset+j, pack_color(0,0,0));
    //     }
    // }
}
