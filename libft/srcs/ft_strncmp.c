/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:57:55 by rrast             #+#    #+#             */
/*   Updated: 2022/03/22 18:00:38 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < (n - 1))
	{
		if (((unsigned char *) s1)[i] != ((unsigned char *) s2)[i])
			break ;
		i++;
	}
	if (((unsigned char *) s1)[i] == ((unsigned char *) s2)[i])
		return (0);
	if (((unsigned char *) s1)[i] > ((unsigned char *) s2)[i])
		return (1);
	return (-1);
}
