/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:29 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:30 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_up(t_data *data)
{
	if (data->moves->up == 1)
	{
		if (data->map[(int)(data->pl->y - sin(data->pl->dir) * SPEED) / SCALE] \
		[(int)data->pl->x / SCALE] != '1' && \
		data->map[(int)(data->pl->y - sin(data->pl->dir) * SPEED) / SCALE] \
		[(int)data->pl->x / SCALE] != 'e')
		{
			data->pl->y -= sin(data->pl->dir) * SPEED;
		}
		if (data->map[(int)data->pl->y / SCALE] \
		[(int)(data->pl->x + cos(data->pl->dir) * SPEED) / SCALE] != '1' \
		&& data->map[(int)data->pl->y / SCALE] \
		[(int)(data->pl->x + cos(data->pl->dir) * SPEED) / SCALE] != 'e')
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
			data->pl->x -= cos(data->pl->dir - M_PI_2) * (SPEED / 2);
		if (data->map[(int)(data->pl->y + sin(data->pl->dir - M_PI_2) \
			* SPEED) / SCALE][(int)data->pl->x / SCALE] != '1' && \
			data->map[(int)(data->pl->y + sin(data->pl->dir - M_PI_2) \
			* SPEED) / SCALE][(int)data->pl->x / SCALE] != 'e')
			data->pl->y += sin(data->pl->dir - M_PI_2) * (SPEED / 2);
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
			data->pl->x -= cos(data->pl->dir + M_PI_2) * (SPEED / 2);
		if (data->map[(int)(data->pl->y + sin(data->pl->dir + M_PI_2) \
			* SPEED) / SCALE][(int)data->pl->x / SCALE] != '1' && \
			data->map[(int)(data->pl->y + sin(data->pl->dir + M_PI_2) \
			* SPEED) / SCALE][(int)data->pl->x / SCALE] != 'e')
			data->pl->y += sin(data->pl->dir + M_PI_2) * (SPEED / 2);
	}
}
