#include "../includes/cub3D.h"

void	check_null_img2(t_data *data)
{
	if (data->pict->no_wall->addr == NULL \
	|| data->pict->ea_wall->addr == NULL \
	|| data->pict->so_wall->addr == NULL \
	|| data->pict->we_wall->addr == NULL \
	|| data->pict->sprite1->img == NULL \
	|| data->pict->sprite1->addr == NULL \
	|| data->pict->sprite2->img == NULL \
	|| data->pict->sprite2->addr == NULL \
	|| data->pict->door->img == NULL \
	|| data->pict->door->addr == NULL)
		ft_exit(data, WRONG_MAP);
}

void	check_identifiers(t_data *data)
{
	int	i;

	init_pict_pointers(data);
	i = -1;
	if (data->map[0] == NULL)
		ft_exit(data, WRONG_MAP);
	while (data->map[++i] && i < 6)
		init_pict(data->map[i], data);
	if (data->pict->ea_wall == NULL || \
	data->pict->no_wall == NULL || \
	data->pict->so_wall == NULL || \
	data->pict->we_wall == NULL)
		ft_exit(data, WRONG_MAP);
	init_data_addr(data);
	check_null_img2(data);
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
	if (res == NULL)
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
