#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + \
	(y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 1)
				// mlx_pixel_put(data->mlx->mlx, data->mlx->win, y, x, 0xFFFFFF);
				my_mlx_pixel_put(data->mlx, x, y, 0x00FF0000);
				mlx_put_image_to_window(data->mlx->mlx, \
				data->mlx->win, data->mlx->img, x, y);
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
}
