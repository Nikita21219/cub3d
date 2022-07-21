/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:12 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:13 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	write_ray(t_data *data, t_ray right_ray, float s_x, float s_y)
{
	data->ray->len_ray = right_ray.len_ray;
	data->ray->x = right_ray.x;
	data->ray->y = right_ray.y;
	data->ray->door = right_ray.door;
	data->ray->s_x = s_x;
	data->ray->s_y = s_y;
}

float	len_vector(t_data data, float x, float y)
{
	return (sqrt(powf(data.pl->x - x, 2.0) \
		+ powf(data.pl->y - y, 2.0)));
}

void	check_len_ray(t_ray hor, t_ray ver, t_data *data, float angle)
{
	if (hor.len_ray != INFINITY)
		hor.len_ray = len_vector(*data, hor.x, hor.y);
	if (ver.len_ray != INFINITY)
		ver.len_ray = len_vector(*data, ver.x, ver.y);
	if (hor.len_ray <= ver.len_ray)
	{
		write_ray(data, hor, 1, 0);
		if (sin(angle) > 0)
			data->ray->s = 'n';
		else
			data->ray->s = 's';
	}
	else
	{
		write_ray(data, ver, 0, 1);
		if (cos(angle) > 0)
			data->ray->s = 'e';
		else
			data->ray->s = 'w';
	}	
}

int	check_wall(t_ray *hv, char **map, int *wall)
{
	int	len_map;
	int	x;
	int	y;

	x = (int)hv->x / SCALE;
	y = (int)hv->y / SCALE;
	len_map = len_arr(map) - 1;
	if (y > len_map || y < 0 || x < 0 \
	|| x > (int)ft_strlen(map[y]))
	{
		hv->len_ray = INFINITY;
		*wall = 1;
		return (1);
	}
	if (map[y][x] == '1')
	{
		*wall = 1;
		return (1);
	}
	return (0);
}
