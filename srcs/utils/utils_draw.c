#include "../../includes/cub3D.h"

void	draw_square(t_data *data, float x, float y)
{
	float	tmp;
	float	tmp2;
	float	tmp3;

	tmp3 = y + 7;
	while (y < tmp3)
	{
		tmp = x;
		tmp2 = tmp + 7;
		while (tmp < tmp2)
			my_mlx_pixel_put(data->mlx, tmp++, y, 0x00FF000);
		y++;
	}
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_X || y >= WIN_Y)
		return ;
	dst = mlx->addr + \
	(y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_block(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	n;

	n = SCALE / 6 + 6;
	while (--n)
	{
		i = SCALE / 6 + 6;
		while (--i)
			my_mlx_pixel_put(mlx, x + i, y + n, color);
	}
}
