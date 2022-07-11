#include "../../includes/cub3D.h"

int	ft_exitbut(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	ft_exit(data, 5);
	return (0);
}

int	ft_hook(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	if (keycode == 0)
		move_left(data);
	if (keycode == 2)
		move_right(data);
	if (keycode == 13)
		move_up(data);
	if (keycode == 1)
		move_down(data);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		ft_exit(data, 5);
	}
	if (keycode == 123)
		around_left(data);
	if (keycode == 124)
		around_right(data);
	draw_map(data);
	return (0);
}

int	mouse(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx->win, &x, &y);
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
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
	draw_map(data);
	mlx_hook(data->mlx->win, 2, (1L << 0), ft_hook, data);
	// mlx_loop_hook(data->mlx->mlx, &mouse, data);
	mlx_hook(data->mlx->win, 17, 0L, ft_exitbut, data);
	mlx_loop(data->mlx->mlx);
}
