#include "../../includes/cub3D.h"

void	around_left(t_data *data)
{
	if (data->moves->turn_left == 1)
	{
		data->pl->dir += 0.004 * SPEED;
		if (data->pl->dir >= 2 * (float)M_PI)
			data->pl->dir -= (float)M_PI * 2;
	}
}

void	around_right(t_data *data)
{
	if (data->moves->turn_right == 1)
	{
		data->pl->dir -= 0.004 * SPEED;
		if (data->pl->dir < 0)
			data->pl->dir += (float)M_PI * 2;
	}
}

void	move_up(t_data *data)
{
	if (data->moves->up == 1)
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
}

void	move_down(t_data *data)
{
	if (data->moves->down == 1)
	{
		if (data->map[(int)(data->pl->y + sin(data->pl->dir) * SPEED) / SCALE] \
		[(int)data->pl->x / SCALE] != '1' && data->map[(int)(data->pl->y \
		+ sin(data->pl->dir) * SPEED) / SCALE] \
		[(int)data->pl->x / SCALE] != 'e')
		{
			data->pl->y += sin(data->pl->dir) * SPEED;
		}
		if (data->map[(int)data->pl->y / SCALE] \
		[(int)(data->pl->x - cos(data->pl->dir) * SPEED) / SCALE] != '1' \
		&& data->map[(int)data->pl->y / SCALE] \
		[(int)(data->pl->x - cos(data->pl->dir) * SPEED) / SCALE] != 'e')
		{
			data->pl->x -= cos(data->pl->dir) * SPEED;
		}
	}
}

void	move_left(t_data *data)
{
	if (data->moves->left == 1)
	{
		if (data->map[(int)data->pl->y / SCALE][(int)(data->pl->x \
			- cos(data->pl->dir - M_PI_2) * SPEED) / SCALE] != '1' \
			&& data->map[(int)data->pl->y / SCALE][(int)(data->pl->x \
			- cos(data->pl->dir - M_PI_2) * SPEED) / SCALE] != 'e')
			data->pl->x -= cos(data->pl->dir - M_PI_2) * (SPEED/2);
		if (data->map[(int)(data->pl->y + sin(data->pl->dir - M_PI_2) \
			* SPEED) / SCALE][(int)data->pl->x / SCALE] != '1' && \
			data->map[(int)(data->pl->y + sin(data->pl->dir - M_PI_2) \
			* SPEED) / SCALE][(int)data->pl->x / SCALE] != 'e')
			data->pl->y += sin(data->pl->dir - M_PI_2) * (SPEED/2);
	}
}

void	move_right(t_data *data)
{
	if (data->moves->right == 1)
	{
		if (data->map[(int)data->pl->y / SCALE][(int)(data->pl->x \
			- cos(data->pl->dir + M_PI_2) * SPEED) / SCALE] != '1' \
			&& data->map[(int)data->pl->y / SCALE][(int)(data->pl->x \
			- cos(data->pl->dir + M_PI_2) * SPEED) / SCALE] != 'e')
			data->pl->x -= cos(data->pl->dir + M_PI_2) * (SPEED/2);
		if (data->map[(int)(data->pl->y + sin(data->pl->dir + M_PI_2) \
			* SPEED) / SCALE][(int)data->pl->x / SCALE] != '1' && \
			data->map[(int)(data->pl->y + sin(data->pl->dir + M_PI_2) \
			* SPEED) / SCALE][(int)data->pl->x / SCALE] != 'e')
			data->pl->y += sin(data->pl->dir + M_PI_2) * (SPEED/2);
	}
}
