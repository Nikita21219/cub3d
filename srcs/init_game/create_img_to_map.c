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
	if (hor.len_ray < ver.len_ray)
		my_mlx_pixel_put(data->mlx, hor.x, hor.y, 0x00FF000);
	else
		my_mlx_pixel_put(data->mlx, ver.x, ver.y, 0x00FF000);
}

void	init_ver(t_ray *ver, t_pl pl)
{
	if (pl.dir < (float)M_PI_2 && pl.dir > (float)(M_PI * 1.5))
		ver->x = (int)pl.x / SCALE * SCALE + SCALE;
	else
		ver->x = (int)pl.x / SCALE * SCALE - 1;
	ver->y = (int)pl.y + (tanf(pl.dir) * fabsf(ver->x - pl.x));
	ver->s_x = SCALE;
	ver->s_y = tanf(pl.dir) * fabsf(ver->s_x);
	if (pl.dir > (float)M_PI_2 && pl.dir < (float)(M_PI * 1.5))
		ver->s_x *= -1;
	ver->len_ray = fabs(sqrt(powf(pl.x - ver->x, 2.0) + powf(pl.y - ver->y, 2.0)));
}

void	init_hor(t_ray *hor, t_pl pl)
{
	if (pl.dir < (float)M_PI)
		hor->y = (int)pl.y / SCALE * SCALE - 1;
	else
		hor->y = (int)pl.y / SCALE * SCALE + SCALE;
	hor->x = (int)pl.x + (fabsf(pl.y - hor->y)) / tanf(pl.dir);
	hor->s_y = SCALE;
	if (pl.dir < (float)M_PI)
		hor->s_y *= -1;
	hor->s_x = fabsf(hor->s_y) / tanf(pl.dir);
	hor->len_ray = fabs(sqrt(powf(pl.x - hor->x, 2.0) + powf(pl.y - hor->y, 2.0)));
}

int	check_wall(t_ray *hv, char **map)
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
			hv->x = SCALE;
		if (x > (int)ft_strlen(map[(int)hv->y / SCALE]))
			hv->x = (int)ft_strlen(map[(int)hv->y / SCALE]) * SCALE;
		return (1);
	}
	if (map[y][x] == '1')
		return (1);
	return (0);
}

void	draw_player(t_data *data)
{
	t_pl	pr;
	t_ray	ver;
	t_ray	hor;
	int		wall_h;
	int		wall_v;

	pr = *data->pl;
	wall_h = 0;
	wall_v = 0;
	init_ver(&ver, *data->pl);
	init_hor(&hor, *data->pl);
	wall_v = check_wall(&ver, data->map);
	wall_h = check_wall(&hor, data->map);
	my_mlx_pixel_put(data->mlx, pr.x, pr.y, 0x00FF000);
	if (data->pl->dir == (float)M_PI_2 || data->pl->dir == (float)(M_PI * 1.5))
		wall_v = 1;
	if ((data->pl->dir == (float)M_PI || data->pl->dir == 0))
		wall_h = 1;
	while (!wall_h || !wall_v)
	{
		if (!wall_v && ver.len_ray <= hor.len_ray)
		{
			ver.x += ver.s_x;
			ver.y += ver.s_y;
			wall_v = check_wall(&ver, data->map);
			ver.len_ray = fabs((data->pl->x - ver.x) / cosf(data->pl->dir));
		}
		if (!wall_h && ver.len_ray >= hor.len_ray)
		{
			hor.x += hor.s_x;
			hor.y += hor.s_y;
			wall_h = check_wall(&hor, data->map);
			hor.len_ray = fabs((data->pl->x - hor.x) / cosf(data->pl->dir));
		}
		if (hor.len_ray > ver.len_ray && wall_v == 1)
			wall_h = 1;
		if (ver.len_ray > hor.len_ray && wall_h == 1)
			wall_v = 1;
		printf("ver y=%d, x=%d, len=%f\n", (int)ver.y / SCALE, (int)ver.x / SCALE, ver.len_ray);
		printf("hor y=%d, x=%d, len=%f\n\n\n", (int)hor.y / SCALE, (int)hor.x / SCALE, hor.len_ray);
		my_mlx_pixel_put(data->mlx, ver.x * 10, ver.y * 10, 0x00FF000);
		my_mlx_pixel_put(data->mlx, hor.x * 10, hor.y * 10, 0x00FF000);
	}
	// check_len_ray(hor, ver, data);
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
