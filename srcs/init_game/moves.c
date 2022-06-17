#include "../../includes/cub3D.h"

void	move_left(t_data *data)
{
	if (data->map[(int)data->pl->y / SCALE][((int)data->pl->x - 1) / SCALE] != '1')
		data->pl->x -= 1;
}

void	move_right(t_data *data)
{
	if (data->map[(int)data->pl->y / SCALE][((int)data->pl->x + 1) / SCALE] != '1')
		data->pl->x += 1;
}

void	move_up(t_data *data)
{
	if (data->map[((int)data->pl->y - 1) / SCALE][(int)data->pl->x / SCALE] != '1')
		data->pl->y -= 1;
}

void	move_down(t_data *data)
{
	if (data->map[((int)data->pl->y + 1) / SCALE][(int)data->pl->x / SCALE] != '1')
		data->pl->y += 1;
}
