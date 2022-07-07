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
	while (data->pl->start >= data->pl->end)
	{
		rays(data, data->pl->start);
		data->ray->len_ray *= cos(data->pl->start - data->pl->dir);
		map3d_draw(*data, pix);
		data->pl->start -= ((FOV * M_PI / 180) / WIN_X);
		pix++;
	}
	draw_2dmap(*data);
	mlx_put_image_to_window(data->mlx->mlx, \
		data->mlx->win, data->mlx->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
}
