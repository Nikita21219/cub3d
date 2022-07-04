#include "../../includes/cub3D.h"

void	around_left(t_data *data)
{
	data->pl->dir += 0.004 * SPEED;
	if (data->pl->dir >= 2 * (float)M_PI)
		data->pl->dir -= (float)M_PI * 2;
}

void	around_right(t_data *data)
{
	data->pl->dir -= 0.004 * SPEED;
	if (data->pl->dir < 0)
		data->pl->dir += (float)M_PI * 2;
}

void	move_up(t_data *data)
{
	if (data->map[(int)(data->pl->y - sin(data->pl->dir) * SPEED) / SCALE] \
	[(int)data->pl->x / SCALE] != '1')
	{
		data->pl->y -= sin(data->pl->dir) * SPEED;
	}
	if (data->map[(int)data->pl->y / SCALE] \
	[(int)(data->pl->x + cos(data->pl->dir) * SPEED) / SCALE] != '1')
	{
		data->pl->x += cos(data->pl->dir) * SPEED;
	}
}

void	move_down(t_data *data)
{
	if (data->map[(int)(data->pl->y + sin(data->pl->dir) * SPEED) / SCALE] \
	[(int)data->pl->x / SCALE] != '1')
	{
		data->pl->y += sin(data->pl->dir) * SPEED;
	}
	if (data->map[(int)data->pl->y / SCALE] \
	[(int)(data->pl->x - cos(data->pl->dir) * SPEED) / SCALE] != '1')
	{
		data->pl->x -= cos(data->pl->dir) * SPEED;
	}
}

void	move_left(t_data *data)
{
	if (data->map[(int)data->pl->y / SCALE][(int)(data->pl->x \
		- cos(data->pl->dir - M_PI_2) * SPEED) / SCALE] != '1')
		data->pl->x -= cos(data->pl->dir - M_PI_2) * SPEED;
	if (data->map[(int)(data->pl->y + sin(data->pl->dir - M_PI_2) \
		* SPEED) / SCALE][(int)data->pl->x / SCALE] != '1')
		data->pl->y += sin(data->pl->dir - M_PI_2) * SPEED;
}

void	move_right(t_data *data)
{
	if (data->map[(int)data->pl->y / SCALE][(int)(data->pl->x \
		- cos(data->pl->dir + M_PI_2) * SPEED) / SCALE] != '1')
		data->pl->x -= cos(data->pl->dir + M_PI_2) * SPEED;
	if (data->map[(int)(data->pl->y + sin(data->pl->dir + M_PI_2) \
		* SPEED) / SCALE][(int)data->pl->x / SCALE] != '1')
		data->pl->y += sin(data->pl->dir + M_PI_2) * SPEED;
}
