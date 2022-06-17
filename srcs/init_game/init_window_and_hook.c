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
	draw_map(data);
	return (0);
}

void	ft_init_window(t_data *data)
{
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, \
	1920, 1080, "A frenzied massacre");
	draw_map(data);
	// mlx_hook(data->mlx->win, 2, (1L << 0), ft_hook, data);
	mlx_hook(data->mlx->win, 17, 0L, ft_exitbut, data);
	mlx_loop(data->mlx->mlx);
}
