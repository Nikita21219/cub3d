#include "../includes/cub3D.h"

int	is_identifier(char *str)
{
	if (startswith(str, "NO") || startswith(str, "SO"))
		return (1);
	if (startswith(str, "EA") || startswith(str, "WE"))
		return (1);
	if (startswith(str, "F") || startswith(str, "C"))
		return (1);
	return (0);
}

void	init_pict(char *str, t_data *data)
{
	int		img_width;
	int		img_height;

	while (ft_space(*str))
		str++;
	if (startswith(str, "NO"))
		data->pict->no_wall = mlx_xpm_file_to_image(data->mlx, ft_strtrim(str + 2, " \t"), &img_width, &img_height);
	else if (startswith(str, "SO"))
		data->pict->so_wall = mlx_xpm_file_to_image(data->mlx, ft_strtrim(str + 2, " \t"), &img_width, &img_height);
	else if (startswith(str, "WE"))
		data->pict->we_wall = mlx_xpm_file_to_image(data->mlx, ft_strtrim(str + 2, " \t"), &img_width, &img_height);
	else if (startswith(str, "EA"))
		data->pict->ea_wall = mlx_xpm_file_to_image(data->mlx, ft_strtrim(str + 2, " \t"), &img_width, &img_height);
	else if (startswith(str, "C"))
		data->pict->ceiling = convert_grb(ft_strtrim(str + 1, " \t"), data);
	else if (startswith(str, "F"))
		data->pict->floor = convert_grb(ft_strtrim(str + 1, " \t"), data);
	else
		ft_exit(data, WRONG_MAP);
}

void	check_identifiers(t_data *data)
{
	int		i;

	data->pict = malloc(sizeof(t_pict));
	if (data->pict == NULL)
		ft_exit(data, 12);
	data->pict->ea_wall = NULL;
	data->pict->no_wall = NULL;
	data->pict->so_wall = NULL;
	data->pict->we_wall = NULL;
	i = -1;
	while (data->map[++i] && i < 6)
		init_pict(data->map[i], data);
	if (data->pict->ea_wall == NULL || \
	data->pict->no_wall == NULL || \
	data->pict->so_wall == NULL || \
	data->pict->we_wall == NULL)
		ft_exit(data, WRONG_MAP);
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
	data->map = res;
}

void	check_mapfile(t_data *data)
{
	set_map(data);
	check_map(data);
}
