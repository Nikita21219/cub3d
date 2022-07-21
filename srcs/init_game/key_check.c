/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:26 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:27 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_exitbut(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	ft_exit(data, 5);
	return (0);
}

int	mouse(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx->win, &x, &y);
	if (data->mouse->x > x)
	{
		data->pl->dir += 0.004 * SPEED;
		if (data->pl->dir >= 2 * (float)M_PI)
			data->pl->dir -= (float)M_PI * 2;
		mlx_mouse_move(data->mlx->win, WIN_X / 2, WIN_Y / 2);
	}
	else if (data->mouse->x < x)
	{
		data->pl->dir -= 0.004 * SPEED;
		if (data->pl->dir < 0)
			data->pl->dir += (float)M_PI * 2;
		mlx_mouse_move(data->mlx->win, WIN_X / 2, WIN_Y / 2);
	}
	return (0);
}

int	ft_press(int key, t_data *data)
{
	if (key == UP)
		data->moves->up = 1;
	if (key == DOWN)
		data->moves->down = 1;
	if (key == LEFT)
		data->moves->left = 1;
	if (key == RIGHT)
		data->moves->right = 1;
	if (key == TURN_LEFT)
		data->moves->turn_left = 1;
	if (key == TURN_RIGHT)
		data->moves->turn_right = 1;
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		ft_exit(data, 5);
	}
	return (0);
}

int	ft_release(int key, t_data *data)
{
	if (key == UP)
		data->moves->up = 0;
	if (key == DOWN)
		data->moves->down = 0;
	if (key == LEFT)
		data->moves->left = 0;
	if (key == RIGHT)
		data->moves->right = 0;
	if (key == TURN_LEFT)
		data->moves->turn_left = 0;
	if (key == TURN_RIGHT)
		data->moves->turn_right = 0;
	return (0);
}

int	mouse_visible(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		mlx_mouse_hide();
		data->mouse->visible = 0;
		mlx_mouse_move(data->mlx->win, WIN_X / 2, WIN_Y / 2);
	}
	if (button == 2)
	{
		mlx_mouse_move(data->mlx->win, WIN_X / 2, WIN_Y / 2);
		mlx_mouse_show();
		data->mouse->visible = 1;
	}
	return (0);
}
