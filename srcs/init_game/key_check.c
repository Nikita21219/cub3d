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
	// mlx_clear_window(data->mlx->mlx, data->mlx->win);
	if (data->mouse->x - 50 > x)
	{
		around_left(data);
		mlx_mouse_move(data->mlx->win, WIN_X / 2, WIN_Y / 2);
	}
	else if (data->mouse->x + 50 < x)
	{
		around_right(data);
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
