#include "../../includes/cub3D.h"

int	ft_exitbut(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	ft_exit(data, 5);
	return (0);
}

int	ft_hook(int keycode, t_data *data)
{
	(void)data;

	if (keycode == 0 || keycode == 123)
		printf("LEFT %d\n", keycode);
	if (keycode == 2 || keycode == 124)
		printf("RIGHT %d\n", keycode);
	if (keycode == 13 || keycode == 126)
		printf("UP %d\n", keycode);
	if (keycode == 1 || keycode == 125)
		printf("DOWN %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		ft_exit(data, 5);
	}
	return (0);
}

void	ft_init_window(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		ft_exit(data, 12);
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, \
	1920, 1080, "A frenzied massacre");
	data->mlx->img = mlx_new_image(data->mlx->mlx, 1920, 1080);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, \
	&data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
	draw_map(data);
	mlx_hook(data->mlx->win, 2, (1L << 0), ft_hook, data);
	mlx_hook(data->mlx->win, 17, 0L, ft_exitbut, data);
	mlx_loop(data->mlx->mlx);
}
