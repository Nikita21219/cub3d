/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:40 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:50:41 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
	}
	if (arr)
		free(arr);
	arr = NULL;
}

void	free_pict(t_data *data)
{
	if (data && data->pict)
	{
		if (data->pict->ea_wall)
		{
			free(data->pict->ea_wall);
			data->pict->ea_wall = NULL;
		}
		if (data->pict->no_wall)
		{
			free(data->pict->no_wall);
			data->pict->no_wall = NULL;
		}
		if (data->pict->so_wall)
		{
			free(data->pict->so_wall);
			data->pict->so_wall = NULL;
		}
		if (data->pict->we_wall)
		{
			free(data->pict->we_wall);
			data->pict->we_wall = NULL;
		}
	}
}

void	check_null(t_data *data, void *ptr)
{
	if (ptr == NULL)
		ft_exit(data, MALLOC_ERR);
}

void	check_is_digit(t_data *data, char **split)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
			if (ft_isdigit(split[i][j]) == 0 && \
			ft_space(split[i][j]) == 0)
				ft_exit(data, WRONG_MAP);
	}
}
