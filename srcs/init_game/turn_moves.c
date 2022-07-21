/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:35 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:36 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	around_left(t_data *data)
{
	if (data->moves->turn_left == 1)
	{
		data->pl->dir += 0.004 * SPEED;
		if (data->pl->dir >= 2 * (float)M_PI)
			data->pl->dir -= (float)M_PI * 2;
	}
}

void	around_right(t_data *data)
{
	if (data->moves->turn_right == 1)
	{
		data->pl->dir -= 0.004 * SPEED;
		if (data->pl->dir < 0)
			data->pl->dir += (float)M_PI * 2;
	}
}
