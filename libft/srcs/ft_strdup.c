/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:57:28 by rrast             #+#    #+#             */
/*   Updated: 2022/03/17 12:40:37 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	n;

	n = ft_strlen(s1);
	s2 = malloc(n + 2);
	if (s2 == NULL)
		return (NULL);
	s2 = ft_memcpy(s2, s1, n + 1);
	return (s2);
}
