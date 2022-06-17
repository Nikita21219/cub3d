#include "../includes/cub3D.h"

void	print_arr(char	**arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		printf("%s\n", arr[i]);
}

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

int	get_map_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i - 6);
}

void	init_pict(char *str, t_data *data)
{
	char	**split;
	int		img_width;
	int		img_height;

	split = ft_split(str, ' ');
	if (split == NULL)
		ft_exit(data, 12);
	// TODO check, if path texture is not correct
	if (equal(split[0], "NO"))
		data->pict->no_wall = mlx_xpm_file_to_image(data->mlx, split[1], &img_width, &img_height);
	else if (equal(split[0], "SO"))
		data->pict->so_wall = mlx_xpm_file_to_image(data->mlx, split[1], &img_width, &img_height);
	else if (equal(split[0], "WE"))
		data->pict->we_wall = mlx_xpm_file_to_image(data->mlx, split[1], &img_width, &img_height);
	else if (equal(split[0], "EA"))
		data->pict->ea_wall = mlx_xpm_file_to_image(data->mlx, split[1], &img_width, &img_height);
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
	{
		init_pict(data->map[i], data);
	}
	printf("data->pict->ea_wall = %p\n", data->pict->ea_wall);
	if (data->pict->ea_wall == NULL || \
	data->pict->no_wall == NULL || \
	data->pict->so_wall == NULL || \
	data->pict->we_wall == NULL)
		ft_exit(data, 4);
}

void	get_only_map(t_data *data)
{
	char	**res;
	int		map_size;
	int		i;
	int		j;

	i = -1;
	while (data->map[++i] && i < 6)
		if (!is_identifier(data->map[i]))
			ft_exit(data, 4);
	check_identifiers(data);
	map_size = get_map_size(data->map);
	if (map_size <= 0)
		ft_exit(data, 4);
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
	get_only_map(data);
	// print_arr(data->map);
}
