/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:56 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:49:57 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_sprite	*alloc_new_sprite(t_data *data, float x, float y)
{
	t_sprite	*new;

	new = malloc(sizeof(t_sprite));
	if (new == NULL)
		ft_exit(data, MALLOC_ERR);
	new->x = x;
	new->y = y;
	new->pict_num = 1;
	return (new);
}

void	add_new_sprite(t_sprite **sprite, t_sprite *new)
{
	t_sprite	*tmp;

	new->next = NULL;
	if (*sprite == NULL)
		*sprite = new;
	else
	{
		tmp = *sprite;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	init_sprites(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map && data->map[++i])
	{
		j = -1;
		while (data->map && data->map[i][++j])
			if (data->map[i][j] == 'e')
				add_new_sprite(&data->sprite, alloc_new_sprite(data, j, i));
	}
}
