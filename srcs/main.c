#include "../includes/cub3D.h"

void	init_data(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	data->pl = malloc(sizeof(t_pl));
	data->pict = malloc(sizeof(t_pict));
	data->ray = malloc(sizeof(t_ray));
	if (!data->mlx || !data->pict || !data->pl || !data->ray)
		ft_exit(data, 12);
}

void	tmp_print_dir_coords(t_data *data)
{
	printf("x = %.1f\ny = %.1f\ndirection = %.1f\n", data->pl->x, data->pl->y, data->pl->dir);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit(NULL, 1);
	init_data(&data);
	parser_map(&data, argv[1]);
	check_mapfile(&data);
	// exit(0);
	ft_init_window(&data);
	return (0);
}
