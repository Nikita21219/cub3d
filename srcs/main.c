#include "../includes/cub3D.h"

void	init_data(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	data->pl = malloc(sizeof(t_pl));
	data->pict = malloc(sizeof(t_pict));
	if (!data->mlx || !data->pict || !data->pl)
		ft_exit(data, 12);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit(NULL, 1);
	init_data(&data);
	parser_map(&data, argv[1]);
	data.pl->dir = -90;
	data.pl->y = 11 * SCALE;
	data.pl->x = 26 * SCALE;
	ft_init_window(&data);
	return (0);
}
