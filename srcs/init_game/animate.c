/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:09 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:10 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	animate(t_data *data)
{
	static int	i = 0;

	if (data->sprite)
	{
		if (i % 2 == 0 && i % 4 != 0)
			data->sprite->pict_num = 1;
		else if (i % 4 == 0)
			data->sprite->pict_num = 2;
		i++;
	}
}
