#include "../../includes/cub3D.h"

void	check_len_ray(t_ray hor, t_ray ver, t_data *data, float angle)
{
	(void)angle;
	hor.len_ray = sqrt(powf((int)data->pl->x - fabsf(hor.x), 2.0) \
	+ powf((int)data->pl->y - fabsf(hor.y), 2.0));
	ver.len_ray = sqrt(powf((int)data->pl->x - fabsf(ver.x), 2.0) + \
	powf((int)data->pl->y - fabsf(ver.y), 2.0));
	// hor.len_ray = fabs((data->pl->x - hor.x) / cos(angle));
	// ver.len_ray = fabs((data->pl->x - ver.x) / cos(angle));
	if (hor.len_ray < ver.len_ray)
	{
		data->ray->len_ray = hor.len_ray;
		data->ray->x = hor.x;
		data->ray->y = hor.y;
	}
	else
	{
		data->ray->len_ray = ver.len_ray;
		data->ray->x = ver.x;
		data->ray->y = ver.y;
	}	
}

void	extreme_values(int x, int y, t_ray *hv, int len_map, char **map)
{
	if (y < 0)
		hv->y = SCALE - 1;
	if (y > len_map)
		hv->y = len_map * SCALE + SCALE;
	if (x < 0)
		hv->x = SCALE - 1;
	if (x > (int)ft_strlen(map[(int)hv->y / SCALE]))
		hv->x = (int)ft_strlen(map[(int)hv->y / SCALE]) * SCALE;
	hv->len_ray = INFINITY;
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
		extreme_values(x, y, hv, len_map, map);
		*wall = 1;
		return (1);
	}
	if (map[y][x] == '1')
	{
		*wall = 1;
		return (1);
	}
	return (0);
}