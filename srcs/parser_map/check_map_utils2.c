/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:41 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:49:42 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_identifiers(t_data *data)
{
	int	i;
	int	roof;
	int	floor;

	roof = 0;
	floor = 0;
	init_pict_pointers(data);
	i = -1;
	if (data->map[0] == NULL)
		ft_exit(data, WRONG_MAP);
	while (data->map[++i] && i < 6)
		init_pict(data->map[i], data, &roof, &floor);
	if (roof != 1 || floor != 1)
		ft_exit(data, WRONG_MAP);
	if (data->pict->ea_wall == NULL || \
	data->pict->no_wall == NULL || \
	data->pict->so_wall == NULL || \
	data->pict->we_wall == NULL)
		ft_exit(data, WRONG_MAP);
	init_data_addr(data);
	check_null_img(data);
}

int	is_only_space(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (!ft_space(str[i]))
			return (0);
	return (1);
}

void	init_res_and_j(char ***res, int *j, int map_size, t_data *data)
{
	*res = malloc((map_size + 1) * sizeof(char *));
	if (*res == NULL)
		ft_exit(data, 12);
	*j = 0;
}

void	set_map(t_data *data)
{
	char	**res;
	int		map_size;
	int		i;
	int		j;

	i = -1;
	while (data->map[++i] && i < 6)
		if (!is_identifier(data->map[i]))
			ft_exit(data, WRONG_MAP);
	while (data->map[i] && is_only_space(data->map[i]))
		i++;
	check_identifiers(data);
	map_size = get_map_size(data->map);
	if (map_size <= 0)
		ft_exit(data, WRONG_MAP);
	init_res_and_j(&res, &j, map_size, data);
	while (data->map[i])
		res[j++] = data->map[i++];
	res[j] = NULL;
	j = -1;
	while (data->map[++j] && j < 6)
		free(data->map[j]);
	free(data->map);
	data->map = res;
}

void	check_mapfile(t_data *data)
{
	set_map(data);
	check_map(data);
	init_sprites(data);
}
