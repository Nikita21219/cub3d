/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:45 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:49:46 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	pict->is_init++;
}

void	init_pict(char *str, t_data *data, int *roof, int *floor)
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
	{
		data->pict->ceiling = convert_grb(ft_strtrim(str + 1, " \t"), data);
		*roof += 1;
	}
	else if (startswith(str, "F"))
	{
		data->pict->floor = convert_grb(ft_strtrim(str + 1, " \t"), data);
		*floor += 1;
	}
	else
		ft_exit(data, WRONG_MAP);
}

void	init_pict_pointers(t_data *data)
{
	check_null(data, data->pict);
	data->pict->ea_wall = malloc(sizeof(t_pict_dt));
	check_null(data, data->pict->ea_wall);
	data->pict->ea_wall->is_init = 0;
	data->pict->no_wall = malloc(sizeof(t_pict_dt));
	check_null(data, data->pict->no_wall);
	data->pict->no_wall->is_init = 0;
	data->pict->so_wall = malloc(sizeof(t_pict_dt));
	check_null(data, data->pict->so_wall);
	data->pict->so_wall->is_init = 0;
	data->pict->we_wall = malloc(sizeof(t_pict_dt));
	check_null(data, data->pict->we_wall);
	data->pict->we_wall->is_init = 0;
	data->pict->sprite1 = malloc(sizeof(t_pict_dt));
	check_null(data, data->pict->sprite1);
	data->pict->sprite2 = malloc(sizeof(t_pict_dt));
	check_null(data, data->pict->sprite2);
	data->pict->door = malloc(sizeof(t_pict_dt));
	check_null(data, data->pict->door);
}

void	check_null_img(t_data *data)
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
