#include "../../includes/cub3D.h"

void	move_left(t_data *data)
{
	data->pl->dir -= 0.1;
	if (data->pl->dir < 0)
		data->pl->dir += M_PI * 2;
	data->pl->dx = cos(data->pl->dir) * 5;
	data->pl->dy = sin(data->pl->dir) * 5;
}

void	move_right(t_data *data)
{
	data->pl->dir += 0.1;
	if (data->pl->dir > 2 * M_PI)
		data->pl->dir -= M_PI * 2;
	data->pl->dx = cos(data->pl->dir) * 5;
	data->pl->dy = sin(data->pl->dir) * 5;
}

void	move_up(t_data *data)
{
	if (data->map[(int)(data->pl->y + sin(data->pl->dir)) / SCALE] \
	[(int)(data->pl->x + cos(data->pl->dir)) / SCALE] != '1')
	{
		data->pl->x += data->pl->dx;
		data->pl->y += data->pl->dy;
	}
}

void	move_down(t_data *data)
{
	if (data->map[(int)(data->pl->y - sin(data->pl->dir)) / SCALE] \
	[(int)(data->pl->x - cos(data->pl->dir)) / SCALE] != '1')
	{
		data->pl->x -= data->pl->dx;
		data->pl->y -= data->pl->dy;
	}
}
