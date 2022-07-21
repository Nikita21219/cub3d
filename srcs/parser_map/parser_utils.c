/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:59 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:00 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	left_top_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j + 1]) || \
	!allow_ch(dt->map[i + 1][j]) || \
	!allow_ch(dt->map[i + 1][j + 1]))
		ft_exit(dt, WRONG_MAP);
}

void	right_top_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i + 1][j]) || \
	!allow_ch(dt->map[i + 1][j - 1]))
		ft_exit(dt, WRONG_MAP);
}

void	left_bot_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j + 1]) || \
	!allow_ch(dt->map[i - 1][j + 1]) || \
	!allow_ch(dt->map[i - 1][j]))
		ft_exit(dt, WRONG_MAP);
}

void	right_bot_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i - 1][j - 1]) || \
	!allow_ch(dt->map[i - 1][j]))
		ft_exit(dt, WRONG_MAP);
}

void	bottom_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i - 1][j - 1]) || \
	!allow_ch(dt->map[i - 1][j]) || \
	!allow_ch(dt->map[i - 1][j + 1]) || \
	!allow_ch(dt->map[i][j + 1]))
		ft_exit(dt, WRONG_MAP);
}
