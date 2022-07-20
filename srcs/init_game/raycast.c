#include "../../includes/cub3D.h"

t_ray	init_ver(t_pl plr, float angle)
{
	t_ray	ver;

	ver.s_x = SCALE;
	if (cos(angle) > 0)
		ver.x = (int)(plr.x) / SCALE * SCALE + SCALE;
	else
	{
		ver.x = (int)(plr.x) / SCALE * SCALE - 0.001;
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
		hor.y = (int)(plr.y) / SCALE * SCALE - 0.001;
		hor.s_y *= -1;
	}
	else
		hor.y = (int)(plr.y) / SCALE * SCALE + SCALE;
	hor.s_x = SCALE / fabs(tan(angle));
	if (cos(angle) < 0)
		hor.s_x *= -1;
	if (cos(angle) < 0)
		hor.x = (int)plr.x - fabs(((int)plr.y - hor.y) / tan(angle));
	else
		hor.x = (int)plr.x + fabs(((int)plr.y - hor.y) / tan(angle));
	return (hor);
}

void	rays(t_data *data, float angle)
{
	t_ray		ver;
	t_ray		hor;
	int			wall_h;
	int			wall_v;

	wall_h = 0;
	wall_v = 0;
	ver = init_ver(*data->pl, angle);
	hor = init_hor(*data->pl, angle);
	while (!wall_h || !wall_v)
	{
		if (!wall_h && !check_wall(&hor, data->map, &wall_h))
		{
			if (data->map[(int)hor.y / SCALE][(int)hor.x / SCALE] == 'd' && data->map[(int)hor.y / SCALE][(int)hor.x / SCALE + 1] == '1' && data->map[(int)hor.y / SCALE][(int)hor.x / SCALE - 1] == '1'\
				&& sqrt(powf(data->pl->x - (hor.x), 2.0) \
				+ powf(data->pl->y - (hor.y), 2.0)) > 128)
			{
				hor.door = 2;
				wall_h = 1;
			}
			else
			{
				hor.x += hor.s_x;
				hor.y += hor.s_y;
			}
		}
		if (!wall_v && !check_wall(&ver, data->map, &wall_v))
		{
			if (data->map[(int)ver.y / SCALE][(int)(ver.x) / SCALE] == 'd' && data->map[(int)ver.y / SCALE + 1][(int)(ver.x) / SCALE] == '1' && data->map[(int)ver.y / SCALE - 1][(int)(ver.x) / SCALE] == '1'\
				&& sqrt(powf(data->pl->x - (ver.x), 2.0) + \
				powf(data->pl->y - (ver.y), 2.0)) > 128)
			{
				ver.door = 1;
				wall_v = 1;
			}
			else
			{
				ver.x += ver.s_x;
				ver.y += ver.s_y;
			}
		}
	}
	check_len_ray(hor, ver, data, angle);
}
