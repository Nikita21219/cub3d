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

void	trim_and_xpm_conv(char *str, t_pict_dt *pict, t_data *data)
{
	int		img_width;
	int		img_height;
	char	*tmp;

	tmp = ft_strtrim(str + 2, " \t");
	pict->img = mlx_xpm_file_to_image(data->mlx, \
	tmp, &img_width, &img_height);
	free(tmp);
	if (pict->img == NULL)
		ft_exit(data, WRONG_MAP);
}

void	init_pict(char *str, t_data *data)
{
	while (ft_space(*str))
		str++;
	if (startswith(str, "NO"))
		trim_and_xpm_conv(str, data->pict->no_wall, data);
	else if (startswith(str, "SO"))
		trim_and_xpm_conv(str, data->pict->so_wall, data);
	else if (startswith(str, "WE"))
		trim_and_xpm_conv(str, data->pict->we_wall, data);
	else if (startswith(str, "EA"))
		trim_and_xpm_conv(str, data->pict->ea_wall, data);
	else if (startswith(str, "C"))
		data->pict->ceiling = convert_grb(ft_strtrim(str + 1, " \t"), data);
	else if (startswith(str, "F"))
		data->pict->floor = convert_grb(ft_strtrim(str + 1, " \t"), data);
	else
		ft_exit(data, WRONG_MAP);
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

