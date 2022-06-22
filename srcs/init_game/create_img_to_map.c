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
	t_pl	pr;

	pr = *data->pl;
	pr.start = data->pl->dir - M_PI_4;
	pr.end = data->pl->dir + M_PI_4;
	while (pr.start < pr.end)
	{
		pr.x = data->pl->x;
		pr.y = data->pl->y;
		while (data->map[(int)(pr.y / SCALE)][(int)(pr.x / SCALE)] != '1')
		{
			pr.x += cos(pr.start);
			pr.y += sin(pr.start);
			my_mlx_pixel_put(data->mlx, pr.x, pr.y, 0x00FF000);
		}
		pr.start += M_PI_2 / 140;
	}
}

// void	draw_player(t_data *data)
// {
// 	t_pl	plr;
// 	float	ry;
// 	float	rx;
// 	float	yo;
// 	float	xo;

// 	plr = *data->pl;
// 	if (plr.dir > M_PI)
// 	{
// 		ry = ((int)ry % 64) * 64;
// 		rx = ((int)rx % 64) * 64;
// 		rx = (plr.y - ry) * atan(plr.x);
// 		yo = -SCALE;
// 		xo = -1 * yo;
// 	}
// 	if (plr.dir < M_PI)
// 	{

// 	}
// }

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	data->mlx->img = mlx_new_image(data->mlx->mlx, WIN_X, WIN_Y);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, \
	&data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_block(data->mlx, x * SCALE, y * SCALE, 0x00FF0000);
			x++;
		}
		y++;
	}
	draw_player(data);
	mlx_put_image_to_window(data->mlx->mlx, \
		data->mlx->win, data->mlx->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
}
