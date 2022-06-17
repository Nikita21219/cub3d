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

	n = SCALE + 1;
	while (--n)
	{
		i = SCALE + 1;
		while (--i)
			my_mlx_pixel_put(mlx, x + i, y + n, color);
	}
}

void	draw_player(t_data *data)
{
	t_pl *pr;
	float	fov;

	pr = data->pl;
	fov = 60;
	pr->start = pr->dir - (fov / 2);
	pr->end = pr->dir + (fov / 2);
	while (pr->start < pr->end)
	{
		pr->x = data->pl->x;
		pr->y = data->pl->y;
		while (data->map[(int)(pr->y / SCALE)][(int)(pr->x / SCALE)] != '1')
		{
			pr->x += cos(pr->dir);
			pr->y += sin(pr->dir);
			my_mlx_pixel_put(data->mlx, data->pl->x + SCALE / 2, data->pl->y + SCALE / 2, 0x00FF000);
		}
		pr->start += fov / 1920;
	}
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
				draw_block(data->mlx, (x + tab) * SCALE, y * SCALE, 0x00FF0000);
			x++;
		}
		y++;
	}
	draw_player(data);
	mlx_put_image_to_window(data->mlx->mlx, \
		data->mlx->win, data->mlx->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
}
