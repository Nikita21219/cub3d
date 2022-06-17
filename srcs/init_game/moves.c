#include "../../includes/cub3D.h"

void	move_left(t_data *data)
{
		data->pl->dir -= 0.1;
}

void	move_right(t_data *data)
{
		data->pl->dir += 0.1;
}

void	move_up(t_data *data)
{
	if (data->map[((int)data->pl->y - SPEED - 1) / SCALE][(int)data->pl->x / SCALE] != '1')
	{
		data->pl->x += cos(data->pl->dir) * SPEED;
		data->pl->y += sin(data->pl->dir) * SPEED;
	}
}

void	move_down(t_data *data)
{
	if (data->map[((int)data->pl->y + SPEED + 1) / SCALE][(int)data->pl->x / SCALE] != '1')
	{
		data->pl->x -= cos(data->pl->dir) * SPEED;
		data->pl->y -= sin(data->pl->dir) * SPEED;
	}
}
