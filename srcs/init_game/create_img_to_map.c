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

void	horizontal_check(t_data	*data, int *wall)
{
	float	a_x;
	float	a_y;

	if (data->pl->dir == 0 || data->pl->dir == (float)M_PI)
	{
		data->ray->hx = data->pl->x;
		data->ray->hy = data->pl->y;
		return ;
	}
	if (data->pl->dir < (float)M_PI)
		data->ray->hy = (data->pl->y / SCALE) * SCALE - 1;
	else
		data->ray->hy = (data->pl->y / SCALE) * SCALE + SCALE;
	data->ray->hx = data->pl->x + (data->pl->y - data->ray->hy) / tan(data->pl->dir);
	a_y = SCALE;
	if (data->pl->dir < (float)M_PI)
		a_y *= -1;
	a_x = a_y / tan(data->pl->dir);
	while ((data->ray->len_ray_h <= data->ray->len_ray_v || data->pl->dir == (float)M_PI_2 || data->pl->dir == ((float)M_PI * 1.5)) && data->map[(int)(data->ray->hy / SCALE)][(int)(data->ray->hx / SCALE)] != '1')
	{
		data->ray->hx += a_x;
		data->ray->hy += a_y;
	}
	my_mlx_pixel_put(data->mlx, data->ray->hx, data->ray->hy , 0x00FF000);
	data->ray->len_ray_h = sqrt(((data->pl->x - data->ray->hx) \
	* (data->pl->x - data->ray->hx)) \
	+ ((data->pl->y - data->ray->hy) * (data->pl->y - data->ray->hy)));
	if (data->map[(int)data->ray->hy / SCALE][(int)data->ray->hx / SCALE] == '1')
		*wall = 1;

}

void	vertical_check(t_data	*data, int *wall)
{
	float	a_x;
	float	a_y;

	if (data->pl->dir < (float)M_PI_2 && data->pl->dir > ((float)M_PI * 1.5))
		data->ray->vx = (data->ray->old_vx / SCALE) * SCALE + SCALE;
	else
		data->ray->vx = (data->ray->old_vx / SCALE) * SCALE - 1;
	data->ray->vy = data->ray->old_vy + \
	(data->ray->old_vx - data->ray->vx) * tan(data->pl->dir);
	a_x = SCALE;
	if (data->pl->dir > (float)M_PI_2 && data->pl->dir < ((float)M_PI * 1.5))
		a_x *= -1;
	a_y = a_x / tan(data->pl->dir);
	data->ray->vx += a_x;
	data->ray->vy += a_y;
	data->ray->len_ray_v = sqrt(((data->pl->x - data->ray->vx) \
	* (data->pl->x - data->ray->vx)) \
	+ ((data->pl->y - data->ray->vy) * (data->pl->y - data->ray->vy)));
	if (data->map[(int)data->ray->vy / SCALE][(int)data->ray->vx / SCALE] == '1')
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
}

void	init_ray(t_data *data)
{
	data->ray->old_hx = data->pl->x;
	data->ray->old_hy = data->pl->y;
	data->ray->old_vx = data->pl->x;
	data->ray->old_vy = data->pl->y;
	data->ray->len_ray_h = 0;
	data->ray->len_ray_v = 0;
}

void	draw_player(t_data *data)
{
	t_pl	pr;
	int		wall;

	pr = *data->pl;
	wall = 0;
	// init_ray(data);
	horizontal_check(data, &wall);
	// while (!wall)
	// {
	// 	if (data->ray->len_ray_h < data->ray->len_ray_v || data->pl->dir == (float)M_PI_2 || \
	// 	data->pl->dir == (float)M_PI * 1.5)
	// 	{
	// 		if (data->pl->dir != 0 && data->pl->dir != (float)M_PI)
	// 			horizontal_check(data, &wall);
	// 	}
	// 	else if (data->pl->dir != (float)M_PI_2 && \
	// 	data->pl->dir != (float)M_PI * 1.5)
	// 		vertical_check(data, &wall);
	// 	data->ray->old_hx = data->ray->hx;
	// 	data->ray->old_hy = data->ray->hy;
	// 	data->ray->old_vx = data->ray->vx;
	// 	data->ray->old_vy = data->ray->vy;
	// }
	// check_len_ray(data);
	// my_mlx_pixel_put(data->mlx, data->ray->x_ray, data->ray->y_ray, 0x00FF000);
	my_mlx_pixel_put(data->mlx, pr.x, pr.y, 0x00FF000);
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
