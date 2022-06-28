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
				draw_block(data.mlx, x * SCALE, y * SCALE, 0x00FF0000);
			x++;
		}
		y++;
	}
	draw_square(&data, data.pl->x, data.pl->y);
}

void	draw_map(t_data *data)
{
	int	deviation;

	data->mlx->img = mlx_new_image(data->mlx->mlx, WIN_X, WIN_Y);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, \
	&data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
	data->pl->start = data->pl->dir + ((FOV / 2) * M_PI / 180);
	data->pl->end = data->pl->dir - ((FOV / 2) * M_PI / 180);
	deviation = FOV / 2;
	draw_2dmap(*data);
	while (data->pl->start >= data->pl->end)
	{
		rays(data, data->pl->start);
		data->pl->start -= ((FOV * M_PI / 180) / WIN_X);
	}
	mlx_put_image_to_window(data->mlx->mlx, \
		data->mlx->win, data->mlx->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
}
