#include "../../includes/cub3D.h"

void	check_filename(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (!(name[i] == '.' && name[i + 1] == 'c' && name[i + 2] == 'u' \
		&& name[i + 3] == 'b' && name[i + 4] == '\0'))
		ft_exit(NULL, 1);
}

void	open_read_map(char *name, t_data *data)
{
	int		fd;

	fd = open(name, O_RDONLY);
	gnl(fd, data);
	close(fd);
}

void	parser_map(t_data *data, char *name)
{
	data->map = NULL;
	check_filename(name);
	open_read_map(name, data);
}
