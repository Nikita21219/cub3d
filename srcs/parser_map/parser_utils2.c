/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:01 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:02 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_zero(t_data *dt, int i, int j)
{
	if (j >= (int)ft_strlen(dt->map[i + 1]) || \
	j >= (int)ft_strlen(dt->map[i - 1]))
		ft_exit(dt, WRONG_MAP);
}

void	check_door(t_data *dt, int i, int j)
{
	if (i > 0 && j > 0 && i < len_arr(dt->map) - 1 \
	&& j < (int)ft_strlen(dt->map[i + 1] - 1) && \
	dt->map[i - 1][j] == '1' && \
	dt->map[i][j + 1] == '1' && \
	dt->map[i + 1][j] == '1' && \
	dt->map[i][j - 1] == '1')
		ft_exit(dt, WRONG_MAP);
	if (!((dt->map[i + 1][j] == '1' && \
	dt->map[i - 1][j] == '1') || \
	((dt->map[i][j + 1] == '1' && \
	dt->map[i][j - 1] == '1'))))
		ft_exit(dt, WRONG_MAP);
}

int	is_not_path(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (!ft_space(str[i]))
			return (0);
	return (1);
}

int	check_rgb_range(t_data *data, int number)
{
	if (number < 0 || number > 255)
		ft_exit(data, WRONG_MAP);
	return (number);
}

int	convert_grb(char *str, t_data *data)
{
	char	**split;
	int		res;

	if (str == NULL)
		ft_exit(data, MALLOC_ERR);
	split = ft_split(str, ',');
	free(str);
	if (split == NULL)
		ft_exit(data, MALLOC_ERR);
	if (len_arr(split) != 3)
		ft_exit(data, WRONG_MAP);
	check_is_digit(data, split);
	res = check_rgb_range(data, ft_atoi(split[0])) << 16 | \
		check_rgb_range(data, ft_atoi(split[1])) << 8 | \
		check_rgb_range(data, ft_atoi(split[2]));
	free_arr(split);
	return (res);
}
