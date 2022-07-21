/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_and_hook.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:23 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:24 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	loop_draw(t_data *data)
{
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	move_up(data);
	move_down(data);
	move_left(data);
	move_right(data);
	around_left(data);
	around_right(data);
	if (!data->mouse->visible)
		mouse(data);
	animate(data);
	draw_map(data);
	return (0);
}

void	ft_init_window(t_data *data)
{
	data->mouse->x = WIN_X / 2;
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, \
	WIN_X, WIN_Y, "A frenzied massacre");
	mlx_mouse_move(data->mlx->win, WIN_X / 2, WIN_Y / 2);
	data->mouse->x = WIN_X / 2;
	draw_map(data);
	mlx_mouse_hook(data->mlx->win, mouse_visible, data);
	mlx_hook(data->mlx->win, 2, 0, ft_press, data);
	mlx_hook(data->mlx->win, 3, 0, ft_release, data);
	mlx_loop_hook(data->mlx->mlx, &loop_draw, data);
	mlx_hook(data->mlx->win, 17, 0L, ft_exitbut, data);
	mlx_loop(data->mlx->mlx);
}
