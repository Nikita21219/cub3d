#include "../../includes/cub3D.h"

void	check_len_ray(t_ray hor, t_ray ver, t_data *data, float angle)
{
	if (hor.len_ray != INFINITY)
		hor.len_ray = fabs((data->pl->y - hor.y) / sin(angle));
	if (ver.len_ray != INFINITY)
		ver.len_ray = fabs((data->pl->x - ver.x) / cos(angle));
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

int	check_wall(t_ray *hv, char **map, int *wall)
{
	int	len_map;
	int	x;
	int	y;

	x = (int)hv->x / SCALE;
	y = (int)hv->y / SCALE;
	len_map = len_arr(map) - 1;
	if (y > len_map || y < 0 || x < 0 \
	|| x > (int)ft_strlen(map[y]))
	{
		hv->len_ray = INFINITY;
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