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

void	check_len_ray(t_ray hor, t_ray ver, t_data *data)
{
	hor.len_ray = sqrt(powf(data->pl->x - fabsf(hor.x), 2.0) + powf(data->pl->y - fabsf(hor.y), 2.0));
	ver.len_ray = sqrt(powf(data->pl->x - fabsf(ver.x), 2.0) + powf(data->pl->y - fabsf(ver.y), 2.0));
	if (hor.len_ray < ver.len_ray)
		my_mlx_pixel_put(data->mlx, hor.x / SCALE * SCALE, hor.y / SCALE * SCALE, 0x00FF000);
	else
		my_mlx_pixel_put(data->mlx, ver.x / SCALE * SCALE, ver.y / SCALE * SCALE, 0x00FF000);
}

t_ray	init_ver(t_pl plr, float angle)
{
	t_ray	ver;

	ver.s_x = SCALE;
	if (cos(angle) > 0)
		ver.x = (int)plr.x / SCALE * SCALE + SCALE;
	else
	{
		ver.x = (int)plr.x / SCALE * SCALE - 1;
		ver.s_x *= -1;
	}
	ver.s_y = SCALE * fabs(tan(angle));
	if (sin(angle) > 0)
		ver.s_y *= -1;
	if (sin(angle) > 0)
		ver.y = (int)plr.y - fabs(((int)plr.x - ver.x) * tan(angle));
	else
		ver.y = (int)plr.y + fabs(((int)plr.x - ver.x) * tan(angle));
	return (ver);
}

t_ray	init_hor(t_pl plr, float angle)
{
	t_ray	hor;

	hor.s_y = SCALE;
	if (sin(angle) > 0)
	{
		hor.y = (int)plr.y / SCALE * SCALE - 1;
		hor.s_y *= -1;
	}
	else
		hor.y = (int)plr.y / SCALE * SCALE + SCALE;
	hor.s_x = SCALE / fabs(tan(angle));
	if (cos(angle) < 0)
		hor.s_x *= -1;
	if (cos(angle) < 0)
		hor.x = (int)plr.x - fabs(((int)plr.y - hor.y) / tan(angle));
	else
		hor.x = (int)plr.x + fabs(((int)plr.y - hor.y) / tan(angle));
	return (hor);
}

int	check_wall(t_ray *hv, char **map, int *wall)
{
	int	len_map;
	int	x;
	int	y;

	x = hv->x / SCALE;
	y = hv->y / SCALE;
	len_map = len_arr(map) - 1;
	if (y > len_map || y < 0 || x < 0 \
	|| x > (int)ft_strlen(map[y]))
	{
		if (y < 0)
			hv->y = SCALE - 1;
		if (y > len_map)
			hv->y = len_map * SCALE + SCALE;
		if (x < 0)
			hv->x = SCALE - 1;
		if (x > (int)ft_strlen(map[(int)hv->y / SCALE]))
			hv->x = (int)ft_strlen(map[(int)hv->y / SCALE]) * SCALE;
		*wall = 1;
		hv->len_ray = INFINITY;
		return (1);
	}
	if (map[y][x] == '1')
	{
		*wall = 1;
		return (1);
	}
	return (0);
}

void	rays(t_data *data, float angle)
{
	t_ray	ver;
	t_ray	hor;
	int		wall_h;
	int		wall_v;

	wall_h = 0;
	wall_v = 0;
	if (angle != ((float)M_PI / 2) && angle != ((float)M_PI * 1.5))
		ver = init_ver(*data->pl, angle);
	else
	{
		wall_v = 1;
		ver.len_ray = INFINITY;
	}
	if (angle != 0 && angle != (float)M_PI)
		hor = init_hor(*data->pl, angle);
	else
	{
		wall_h = 1;
		hor.len_ray = INFINITY;
	}
	while (!wall_h || !wall_v)
	{
		if (!wall_h && !check_wall(&hor, data->map, &wall_h))
		{
			hor.x += hor.s_x;
			hor.y += hor.s_y;
		}
		if (!wall_v && !check_wall(&ver, data->map, &wall_v))
		{
			ver.x += ver.s_x;
			ver.y += ver.s_y;
		}
	}
	check_len_ray(hor, ver, data);
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
	data->pl->start = data->pl->dir - M_PI / 6;
	data->pl->end = data->pl->dir + M_PI / 6;
	draw_square(data, data->pl->x, data->pl->y);
	while (data->pl->start <= data->pl->end)
	{
		rays(data, data->pl->start);
		data->pl->start += (M_PI / 3 / WIN_X);
	}
	// rays(data, data->pl->dir);
	mlx_put_image_to_window(data->mlx->mlx, \
		data->mlx->win, data->mlx->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
}
