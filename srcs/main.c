#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit(NULL, 1);
	data = parser_map(argv[1]);
	clearmap(data.map);
	return (0);
}
