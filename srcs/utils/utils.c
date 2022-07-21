/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:30 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:49:31 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	clearmap(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free (map[i++]);
	if (map)
		free (map);
}

/**
 * 1 - Wrong map name
 * 2 - Please, take path and map name (template: path/name)
 * 3 - Map can't open
 * 4 - Map is wrong!
 * 12 - Malloc error.
 * */
void	ft_exit(t_data *data, int i)
{
	if (i == WRONG_MAP_NAME || i == PATH_MAP_ERR \
	|| i == OPEN_MAP_ERR || i == WRONG_MAP)
		printf("Error\n");
	if (i == WRONG_MAP_NAME)
		printf("Wrong map name\n");
	if (i == PATH_MAP_ERR)
		printf("Please, take path and map name (template: path/name)\n");
	if (i == OPEN_MAP_ERR)
		printf("Map can't open\n");
	if (i == WRONG_MAP)
		printf("Map is wrong!\n");
	if (i == MALLOC_ERR)
		printf("Malloc error\n");
	if (data && data->map)
		clearmap(data->map);
	exit (i);
}

void	gnl(int fd, t_data *data)
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
			ft_exit(data, 12);
	}
	data->map = ft_split(line, '\n');
	free(line);
	if (!data->map && c[0])
		ft_exit(data, 12);
	if (!data->map && !c[0])
		ft_exit(data, 4);
}

int	exit_with_print(char *err_str)
{
	printf("%s\n", err_str);
	exit (1);
}
