#include "../../includes/cub3D.h"

void	move_left(t_data *data)
{
	data->pl->dir += 0.1;
	if (data->pl->dir >= 2 * (float)M_PI)
		data->pl->dir -= (float)M_PI * 2;
	data->pl->dx = cosf(data->pl->dir) * 5;
	data->pl->dy = sinf(data->pl->dir) * 5;
}

void	move_right(t_data *data)
{
	data->pl->dir -= 0.1;
	if (data->pl->dir < 0)
		data->pl->dir += (float)M_PI * 2;
	data->pl->dx = cosf(data->pl->dir) * 5;
	data->pl->dy = sinf(data->pl->dir) * 5;
}

void	move_up(t_data *data)
{
	if (data->map[(int)(data->pl->y - data->pl->dy * SPEED) / SCALE] \
	[(int)data->pl->x / SCALE] != '1')
	{
		data->pl->y -= data->pl->dy * SPEED;
	}
	if (data->map[(int)data->pl->y / SCALE] \
	[(int)(data->pl->x + data->pl->dx * SPEED) / SCALE] != '1')
	{
		data->pl->x += data->pl->dx * SPEED;
	}
}

void	move_down(t_data *data)
{
	if (data->map[(int)(data->pl->y + data->pl->dy * SPEED) / SCALE] \
	[(int)data->pl->x / SCALE] != '1')
	{
		data->pl->y += data->pl->dy * SPEED;
	}
	if (data->map[(int)data->pl->y / SCALE] \
	[(int)(data->pl->x - data->pl->dx * SPEED) / SCALE] != '1')
	{
		data->pl->x -= data->pl->dx * SPEED;
	}
}
