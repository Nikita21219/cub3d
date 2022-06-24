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

int	check_x_y_win(float *x, float *y)
{
	if (*x < 0 || *y < 0 || *x > (float)WIN_X || *y > (float)WIN_Y)
	{
		if (*x < 0)
			*x = 0;
		if (*y < 0)
			*y = 0;
		if (*x > WIN_X)
			*x = WIN_X;
		if (*y > WIN_Y)
			*y = WIN_Y;
		return (1);
	}
	return (0);
}

void	horizontal_check(t_data	*data, int *wall)
{
	float	a_x;
	float	a_y;
	t_ray	*ray;

	ray = data->ray;
	ray->hy = (int)(data->pl->y / SCALE) * SCALE;
	ray->hx = (int)(data->pl->x / SCALE) * SCALE + ((fabsf(data->pl->y - ray->hy)) / tan(data->pl->dir));
	a_y = SCALE;
	if (data->pl->dir < (float)M_PI)
		a_y *= -1;
	a_x = fabsf(a_y) / tan(data->pl->dir);
	while (data->map[(int)ray->hy / SCALE][(int)ray->hx / SCALE] != '1')
	{
		printf("%c\n", data->map[(int)ray->hy / SCALE][(int)ray->hx / SCALE]);
		printf("y = %d\nx = %d\n\n", (int)ray->hy / SCALE, (int)ray->hx / SCALE);
		ray->hx += a_x;
		ray->hy += a_y;
		if (check_x_y_win(&ray->hx, &ray->hy))
			break ;
	}
	ray->len_ray_h = fabs((data->pl->x - ray->hx) / cos(data->pl->dir));
	*wall = 1;
}

void	vertical_check(t_data	*data, int *wall)
{
	float	a_x;
	float	a_y;
	t_ray	*ray;

	ray = data->ray;
	ray->vx = (int)data->pl->x / SCALE * SCALE;
	ray->vy = (int)data->pl->y + (tan(data->pl->dir) * fabsf(ray->vx - data->pl->x));
	a_x = SCALE;
	if (data->pl->dir > (float)M_PI_2 && data->pl->dir < (float)(M_PI * 1.5))
		a_x *= -1;
	a_y = tan(data->pl->dir) * fabsf(a_x - data->pl->x);
	while (data->map[(int)ray->vy / SCALE][(int)ray->vx / SCALE] != '1')
	{
		ray->vx += a_x;
		ray->vy += a_y;
		if (check_x_y_win(&ray->vx, &ray->vy))
			break ;
	}
	ray->len_ray_v = fabs((data->pl->x - ray->vx) / cos(data->pl->dir));
	*wall = 1;
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
	my_mlx_pixel_put(data->mlx, data->ray->x_ray, data->ray->y_ray, 0x00FF000);
}

void	draw_player(t_data *data)
{
	t_pl	pr;
	int		wall_h;
	int		wall_v;

	pr = *data->pl;
	wall_h = 0;
	wall_v = 0;
	data->ray->len_ray_h = 0;
	data->ray->len_ray_v = 0;
	my_mlx_pixel_put(data->mlx, pr.x, pr.y, 0x00FF000);
	while (!wall_h && !wall_v)
	{
		if ((data->pl->dir != (float)M_PI_2 && data->pl->dir != (float)(M_PI * 1.5)) && !wall_v)
			vertical_check(data, &wall_v);
		if ((data->pl->dir != (float)M_PI && data->pl->dir != 0) && !wall_h)
			horizontal_check(data, &wall_h);
		if ((data->pl->dir != (float)M_PI && data->pl->dir != 0) && wall_v)
			wall_h = 1;
		if (data->pl->dir != (float)M_PI_2 && data->pl->dir != (float)(M_PI * 1.5))
			wall_v = 1;
	}
	check_len_ray(data);
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
