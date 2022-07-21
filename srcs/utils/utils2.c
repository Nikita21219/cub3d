/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:33 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:49:34 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	len_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	get_map_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i - 6);
}

int	not_sorted(t_sprite *sprite)
{
	while (sprite && sprite->next)
	{
		if (sprite->len < sprite->next->len)
			return (1);
		sprite = sprite->next;
	}
	return (0);
}

void	swap_values(t_sprite *sp)
{
	float		tmp_x;
	float		tmp_y;
	float		tmp_dir;
	float		tmp_len;

	tmp_x = sp->x;
	tmp_y = sp->y;
	tmp_dir = sp->dir;
	tmp_len = sp->len;
	sp->x = sp->next->x;
	sp->y = sp->next->y;
	sp->dir = sp->next->dir;
	sp->len = sp->next->len;
	sp->next->x = tmp_x;
	sp->next->y = tmp_y;
	sp->next->dir = tmp_dir;
	sp->next->len = tmp_len;
}

void	sort_sprites(t_sprite *sprite)
{
	t_sprite	*sp;

	sp = sprite;
	while (sp && not_sorted(sprite))
	{
		while (sp && sp->next)
		{
			if (sp->len < sp->next->len)
				swap_values(sp);
			sp = sp->next;
		}
		sp = sprite;
	}
}
