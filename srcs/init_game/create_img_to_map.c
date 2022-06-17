#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + \
	(y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_block(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	n;

	n = 30;
	while (n)
	{
		i = 30;
		while (i)
		{
			my_mlx_pixel_put(mlx, x + i, y + n, color);
			i--;
		}
		n--;
	}
}

void	draw_player(t_data *data)
{
	draw_block(data->mlx, data->pl->x, data->pl->y, 0x0FFFFFF);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	int	tab;

	data->mlx->img = mlx_new_image(data->mlx->mlx, 1920, 1080);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, \
	&data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
	y = 0;
	while (data->map[y])
	{
		tab = 0;
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 9)
				tab += 3;
			if (data->map[y][x] == '1')
				draw_block(data->mlx, (x + tab) * 30, y * 30, 0x00FF0000);
			x++;
		}
		y++;
	}
	draw_player(data);
	mlx_put_image_to_window(data->mlx->mlx, \
		data->mlx->win, data->mlx->img, 500, 350);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
}
