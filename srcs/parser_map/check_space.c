/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:48 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:49:49 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	left_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i - 1][j]) || \
	!allow_ch(dt->map[i - 1][j + 1]) || \
	!allow_ch(dt->map[i][j + 1]) || \
	!allow_ch(dt->map[i + 1][j + 1]) || \
	!allow_ch(dt->map[i + 1][j]))
		ft_exit(dt, WRONG_MAP);
}

void	right_space_handle(t_data *dt, int i, int j)
{
	if ((j <= (int)ft_strlen(dt->map[i - 1]) \
	&& !allow_ch(dt->map[i - 1][j])) || \
	(j - 1 <= (int)ft_strlen(dt->map[i - 1]) \
	&& !allow_ch(dt->map[i - 1][j - 1])) || \
	(j - 1 <= (int)ft_strlen(dt->map[i]) && \
	!allow_ch(dt->map[i][j - 1])) || \
	(j - 1 <= (int)ft_strlen(dt->map[i + 1]) && \
	!allow_ch(dt->map[i + 1][j - 1])) || \
	(j <= (int)ft_strlen(dt->map[i + 1]) && \
	!allow_ch(dt->map[i + 1][j])))
		ft_exit(dt, WRONG_MAP);
}

void	top_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i + 1][j - 1]) || \
	!allow_ch(dt->map[i + 1][j]) || \
	!allow_ch(dt->map[i + 1][j + 1]) || \
	!allow_ch(dt->map[i][j + 1]))
		ft_exit(dt, WRONG_MAP);
}

void	other_space_handle(t_data *dt, int i, int j)
{
	if ((j - 1 <= (int)ft_strlen(dt->map[i - 1]) && \
	!allow_ch(dt->map[i - 1][j - 1])) || \
	(j <= (int)ft_strlen(dt->map[i - 1]) && \
	!allow_ch(dt->map[i - 1][j])) || \
	(j <= (int)ft_strlen(dt->map[i - 1]) && \
	!allow_ch(dt->map[i - 1][j + 1])) || \
	(j + 1 <= (int)ft_strlen(dt->map[i]) && \
	!allow_ch(dt->map[i][j + 1])) || \
	(j + 1 <= (int)ft_strlen(dt->map[i + 1]) && \
	!allow_ch(dt->map[i + 1][j + 1])) || \
	(j <= (int)ft_strlen(dt->map[i + 1]) && \
	!allow_ch(dt->map[i + 1][j])) || \
	(j - 1 <= (int)ft_strlen(dt->map[i + 1]) && \
	!allow_ch(dt->map[i + 1][j - 1])) || \
	(j - 1 <= (int)ft_strlen(dt->map[i]) && \
	!allow_ch(dt->map[i][j - 1])))
		ft_exit(dt, WRONG_MAP);
}

void	check_space(t_data *dt, int i, int j)
{
	if (i == 0 && j == 0)
		left_top_space_handle(dt, i, j);
	else if (i == 0 && j == (int) ft_strlen(dt->map[i]) - 1)
		right_top_space_handle(dt, i, j);
	else if (i == len_arr(dt->map) - 1 && j == 0)
		left_bot_space_handle(dt, i, j);
	else if (i == len_arr(dt->map) - 1 && j == (int) ft_strlen(dt->map[i]) - 1)
		right_bot_space_handle(dt, i, j);
	else if (j == 0)
		left_space_handle(dt, i, j);
	else if (j == (int) ft_strlen(dt->map[i]) - 1)
		right_space_handle(dt, i, j);
	else if (i == len_arr(dt->map) - 1)
		bottom_space_handle(dt, i, j);
	else if (i == 0)
		top_space_handle(dt, i, j);
	else
		other_space_handle(dt, i, j);
}
