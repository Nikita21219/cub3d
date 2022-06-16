#include "../../includes/cub3D.h"

void	clearmap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free (map[i++]);
	free (map);
}

/**
 * 0 - Wrong map name
 * 1 - Please, take path and map name (template: path/name)
 * 2 - Map can't open
 * 3 - Map is wrong!
 * 12 - Malloc error.
 * */
void	ft_exit(t_data *data, int i)
{
	if (i == 1)
		printf("Wrong map name\n");
	if (i == 2)
		printf("Please, take path and map name (template: path/name)\n");
	if (i == 3)
		printf("Map can't open\n");
	if (i == 4)
		printf("Map is wrong!\n");
	if (i == 12)
		printf("Malloc error\n");
	if (data && data->map)
		clearmap(data->map);
	exit (i);
}

int	gnl(int fd, t_data *data)
{
	char	*line;
	char	*tmp;
	char	c[2];
	int		i;

	i = 0;
	line = NULL;
	if (fd < 0 || read(fd, NULL, 0) < 0)
		ft_exit(NULL, 2);
	while (read(fd, &c[0], 1))
	{
		c[1] = 0;
		tmp = line;
		line = ft_strjoin(tmp, c);
		if (tmp)
			free(tmp);
		if (!line)
			return (1);
	}
	data->map = ft_split(line, '\n');
	free(line);
	if (!data->map)
		return (1);
	return (0);
}

int	exit_with_print(char *err_str)
{
	printf("%s\n", err_str);
	exit (1);
}
