/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:57:14 by rrast             #+#    #+#             */
/*   Updated: 2022/03/17 12:39:59 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;
	char	*sdest;

	sdest = (char *) dest;
	i = 0;
	while (i < n)
	{
		sdest[i] = c;
		i++;
	}
	return (sdest);
}
