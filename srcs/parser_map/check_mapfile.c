#include "../includes/cub3D.h"

int	is_identifier(char *str)
{
	if ((startswith(str, "NO") || startswith(str, "SO") || \
	startswith(str, "EA") || startswith(str, "WE") || \
	startswith(str, "F") || startswith(str, "C")) && \
	is_not_path(str + 2))
		return (1);
	if (startswith(str, "NO") || startswith(str, "SO"))
		return (1);
	if (startswith(str, "EA") || startswith(str, "WE"))
		return (1);
	if (startswith(str, "F") || startswith(str, "C"))
		return (1);
	return (0);
}

void	check_null_img(t_data *data, void *ptr)
{
	if (ptr == NULL)
		ft_exit(data, WRONG_MAP);
}

void	init_pict(char *str, t_data *data)
{
	int		img_width;
	int		img_height;
	char	*tmp;

	tmp = NULL;
	while (ft_space(*str))
		str++;
	if (startswith(str, "NO"))
	{
		tmp = ft_strtrim(str + 2, " \t");
		data->pict->no_wall->img = mlx_xpm_file_to_image(data->mlx, \
		tmp, &img_width, &img_height);
		check_null_img(data, data->pict->no_wall->img);
	}
	else if (startswith(str, "SO"))
	{
		tmp = ft_strtrim(str + 2, " \t");
		data->pict->so_wall->img = mlx_xpm_file_to_image(data->mlx, \
		tmp, &img_width, &img_height);
		check_null_img(data, data->pict->so_wall->img);
	}
	else if (startswith(str, "WE"))
	{
		tmp = ft_strtrim(str + 2, " \t");
		data->pict->we_wall->img = mlx_xpm_file_to_image(data->mlx, \
		tmp, &img_width, &img_height);
		check_null_img(data, data->pict->we_wall->img);
	}
	else if (startswith(str, "EA"))
	{
		tmp = ft_strtrim(str + 2, " \t");
		data->pict->ea_wall->img = mlx_xpm_file_to_image(data->mlx, \
		tmp, &img_width, &img_height);
		check_null_img(data, data->pict->ea_wall->img);
	}
	else if (startswith(str, "C"))
		data->pict->ceiling = convert_grb(ft_strtrim(str + 1, " \t"), data);
	else if (startswith(str, "F"))
		data->pict->floor = convert_grb(ft_strtrim(str + 1, " \t"), data);
	else
		ft_exit(data, WRONG_MAP);
	free(tmp);
}

void	init_pict_pointers(t_data *data)
{
	if (data->pict == NULL)
		ft_exit(data, MALLOC_ERR);
	data->pict->ea_wall = malloc(sizeof(t_pict_dt));
	if (data->pict->ea_wall == NULL)
		ft_exit(data, MALLOC_ERR);
	data->pict->no_wall = malloc(sizeof(t_pict_dt));
	if (data->pict->no_wall == NULL)
		ft_exit(data, MALLOC_ERR);
	data->pict->so_wall = malloc(sizeof(t_pict_dt));
	if (data->pict->so_wall == NULL)
		ft_exit(data, MALLOC_ERR);
	data->pict->we_wall = malloc(sizeof(t_pict_dt));
	if (data->pict->we_wall == NULL)
		ft_exit(data, MALLOC_ERR);
	data->pict->sprite1 = malloc(sizeof(t_pict_dt));
	if (data->pict->sprite1 == NULL)
		ft_exit(data, MALLOC_ERR);
	data->pict->sprite2 = malloc(sizeof(t_pict_dt));
	if (data->pict->sprite2 == NULL)
		ft_exit(data, MALLOC_ERR);
	data->pict->door = malloc(sizeof(t_pict_dt));
	if (data->pict->door == NULL)
		ft_exit(data, MALLOC_ERR);
}

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
	res = malloc((map_size + 1) * sizeof(char *));
	if (res == NULL)
		ft_exit(data, 12);
	j = 0;
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
