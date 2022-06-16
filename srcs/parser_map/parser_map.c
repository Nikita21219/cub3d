#include "../../includes/cub3D.h"

void	check_filename(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (!(name[i] == '.' && name[i + 1] == 'c' && name[i + 2] == 'u' \
		&& name[i + 3] == 'b' && name[i + 4] == '\0'))
		ft_exit(NULL, 0);
}

void	open_read_map(char *name, t_data *data)
{
	int		i;
	int		fd;

	fd = open(name, O_RDONLY);
	if (gnl(fd, data))
		ft_exit(data, 12);
	i = 0;
	while (data->map[i])
		printf("%s\n", data->map[i++]);
	close(fd);
}

t_data	parser_map(char *name)
{
	t_data	data;

	data.map = NULL;
	check_filename(name);
	open_read_map(name, &data);
	return (data);
}
