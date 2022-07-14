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
			data.map[y][x] == 'S' || data.map[y][x] == 'E' || data.map[y][x] == 'W')
				draw_block(data.mlx, x * SCALE / 6, y * SCALE / 6, 0xFFFFFF);
			x++;
		}
		y++;
	}
	draw_square(&data, (int)data.pl->x / 6, (int)data.pl->y / 6);
}

void	draw_map(t_data *data)
{
	int	pix;

	pix = 0;
	data->mlx->img = mlx_new_image(data->mlx->mlx, WIN_X, WIN_Y);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, \
	&data->mlx->bpp, &data->mlx->line_l, &data->mlx->endian);
	data->pl->start = data->pl->dir + ((FOV / 2) * M_PI / 180);
	data->pl->end = data->pl->dir - ((FOV / 2) * M_PI / 180);
	if (data->sprite)
	{
		data->sprite->dir = atan2((data->pl->y) - (data->sprite->y * SCALE + SCALE / 2), (data->sprite->x * SCALE + SCALE / 2) - (data->pl->x));
		while (data->sprite->dir - data->pl->dir > M_PI)
			data->sprite->dir -= 2 * M_PI;
		while (data->sprite->dir - data->pl->dir < -M_PI)
			data->sprite->dir += 2 * M_PI;
		data->sprite->len = sqrt(pow((data->pl->x / SCALE) - (data->sprite->x), 2) + pow(data->pl->y / SCALE - (data->sprite->y), 2));
	}
	// printf("dr = %f\n", data->sprite->dir);
	while (data->pl->start >= data->pl->end)
	{
		rays(data, data->pl->start);
		data->ray->len_ray *= cos(data->pl->start - data->pl->dir);
		map3d_draw(*data, pix);
		if (data->sprite->dir > data->pl->start - ((FOV * M_PI / 180) / WIN_X) && data->sprite->dir < data->pl->start)
			data->sprite->dx = pix;
		data->pl->start -= ((FOV * M_PI / 180) / WIN_X);
		pix++;
	}
	if (data->sprite && data->sprite->dx != 0)
		draw_sprites(data);
	data->sprite->dx = 0;
	draw_2dmap(*data);
	mlx_put_image_to_window(data->mlx->mlx, \
		data->mlx->win, data->mlx->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
}
