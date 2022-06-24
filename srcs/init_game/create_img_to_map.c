#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

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

int	check_x_y_win(int x, int y)
{
	if (x < 0 || y < 0 || x > WIN_X || y > WIN_Y)
	{
		if (x < 0)
			x = SCALE - 1;
		if (y < 0)
			y = SCALE - 1;
		if (x > WIN_X)
			x = WIN_X - SCALE + 1;
		if (y > WIN_Y)
			y = WIN_Y - SCALE + 1;
		return (1);
	}
	return (0);
}

void	horizontal_check(t_data	*data)
{
	float	a_x;
	float	a_y;
	t_ray	*ray;

	ray = data->ray;
	if (data->pl->dir == (float)M_PI || data->pl->dir == 0)
	{
		ray->hx = data->pl->x;
		ray->hy = data->pl->y;
		return ;
	}
	ray->hy = data->pl->y / SCALE * SCALE;
	ray->hx = (data->pl->x / SCALE * SCALE) + ((fabsf(data->pl->y - ray->hy)) / tan(data->pl->dir));
	a_y = SCALE;
	if (data->pl->dir < M_PI)
		a_y *= -1;
	a_x = fabsf(a_y) / tan(data->pl->dir);
	while (data->map[(int)(ray->hy / SCALE)][(int)(ray->hx / SCALE)] != '1' && ray->len_ray_h < ray->len_ray_v)
	{
		my_mlx_pixel_put(data->mlx, ray->hx, ray->hy, 0x00FF000);
		ray->hx += a_x;
		ray->hy += a_y;
		if (check_x_y_win(ray->hx, ray->hy))
			break ;
		ray->len_ray_h = fabsf(data->pl->x - ray->hx) / cos(data->pl->dir);
	}
	my_mlx_pixel_put(data->mlx, ray->hx, ray->hy, 0x00FF000);
}

void	vertical_check(t_data	*data)
{
	float	a_x;
	float	a_y;
	t_ray	*ray;

	ray = data->ray;
	if (data->pl->dir == (float)M_PI_2 || data->pl->dir == (float)(M_PI * 1.5))
	{
		ray->vx = data->pl->x;
		ray->vy = data->pl->y;
		return ;
	}
	ray->vx = data->pl->x / SCALE * SCALE;
	ray->vy	= data->pl->y + (tan(data->pl->dir) * fabsf(ray->vx - data->pl->x));
	a_x = SCALE;
	if (data->pl->dir > M_PI_2 && data->pl->dir < (M_PI * 1.5))
		a_x *= -1;
	a_y = tan(data->pl->dir) * fabsf(a_x);
	while (data->map[(int)(ray->vy / SCALE)][(int)(ray->vx / SCALE)] != '1' && ray->len_ray_h >= ray->len_ray_v)
	{
		my_mlx_pixel_put(data->mlx, ray->vx, ray->vy, 0x00FF000);
		ray->vx += a_x;
		ray->vy += a_y;
		if (check_x_y_win(ray->vx, ray->vy))
			break ;
		ray->len_ray_v = fabsf(data->pl->x - ray->vx) / cos(data->pl->dir);
	}
	my_mlx_pixel_put(data->mlx, ray->vx, ray->vy, 0x00FF000);
}

void	check_len_ray(t_data *data)
{
	if (data->ray->len_ray_h < data->ray->len_ray_v)
	{
		data->ray->x_ray = data->ray->hx;
		data->ray->y_ray = data->ray->hy;
		data->ray->len_ray = data->ray->len_ray_h;
	}
	else
	{
		data->ray->x_ray = data->ray->vx;
		data->ray->y_ray = data->ray->vy;
		data->ray->len_ray = data->ray->len_ray_v;
	}
}

void	draw_player(t_data *data)
{
	t_pl	pr;
	int		wall;

	pr = *data->pl;
	wall = 0;
	data->ray->len_ray_h = 0;
	data->ray->len_ray_v = 0;
	my_mlx_pixel_put(data->mlx, pr.x, pr.y, 0x00FF000);
	horizontal_check(data);
	vertical_check(data);
}

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
