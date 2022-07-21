/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:51 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:49:52 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	xpm_convert(t_data *data)
{
	t_pict	*pict;
	int		img_width;
	int		img_height;

	pict = data->pict;
	pict->sprite1->img = mlx_xpm_file_to_image(data->mlx, \
	"./texture/sprite1.xpm", &img_width, &img_height);
	if (pict->sprite1->img == NULL)
		ft_exit(data, MALLOC_ERR);
	pict->sprite2->img = mlx_xpm_file_to_image(data->mlx, \
	"./texture/sprite2.xpm", &img_width, &img_height);
	if (pict->sprite2->img == NULL)
		ft_exit(data, MALLOC_ERR);
	pict->door->img = mlx_xpm_file_to_image(data->mlx, \
	"./texture/door.xpm", &img_width, &img_height);
	if (pict->door->img == NULL)
		ft_exit(data, MALLOC_ERR);
}

void	check_init_pictures(t_data *data, t_pict *pict)
{
	if (pict->ea_wall->is_init != 1 || pict->no_wall->is_init != 1 || \
	pict->we_wall->is_init != 1 || pict->so_wall->is_init != 1)
		ft_exit(data, WRONG_MAP);
}

void	init_data_addr(t_data *data)
{
	t_pict	*pict;

	pict = data->pict;
	xpm_convert(data);
	check_init_pictures(data, pict);
	pict->sprite2->addr = mlx_get_data_addr(pict->sprite2->img, \
	&pict->sprite2->bpp, &pict->sprite2->line_l, &pict->sprite2->endian);
	pict->sprite1->addr = mlx_get_data_addr(pict->sprite1->img, \
	&pict->sprite1->bpp, &pict->sprite1->line_l, &pict->sprite1->endian);
	pict->no_wall->addr = mlx_get_data_addr(pict->no_wall->img, \
	&pict->no_wall->bpp, &pict->no_wall->line_l, &pict->no_wall->endian);
	pict->ea_wall->addr = mlx_get_data_addr(pict->ea_wall->img, \
	&pict->ea_wall->bpp, &pict->ea_wall->line_l, &pict->ea_wall->endian);
	pict->so_wall->addr = mlx_get_data_addr(pict->so_wall->img, \
	&pict->so_wall->bpp, &pict->so_wall->line_l, &pict->so_wall->endian);
	pict->we_wall->addr = mlx_get_data_addr(pict->we_wall->img, \
	&pict->we_wall->bpp, &pict->we_wall->line_l, &pict->we_wall->endian);
	pict->door->addr = mlx_get_data_addr(pict->door->img, \
	&pict->door->bpp, &pict->door->line_l, &pict->door->endian);
}
