/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:19 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:49:20 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_data(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	data->pl = malloc(sizeof(t_pl));
	data->pict = malloc(sizeof(t_pict));
	data->ray = malloc(sizeof(t_ray));
	data->mouse = malloc(sizeof(t_mouse));
	data->moves = malloc(sizeof(t_moves));
	data->n_ray = malloc(sizeof(float) * (WIN_X + 1));
	if (!data->mlx || !data->pict || !data->pl || !data->ray \
	|| !data->mouse || !data->n_ray)
		ft_exit(data, 12);
	data->sprite = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit(NULL, 1);
	init_data(&data);
	parser_map(&data, argv[1]);
	check_mapfile(&data);
	ft_init_window(&data);
	return (0);
}
