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
	(void)	color;

	if (x < 0 || y < 0)
		return ;
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
