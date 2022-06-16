/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:22:29 by rrast             #+#    #+#             */
/*   Updated: 2022/03/17 12:41:06 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	l;
	size_t	i;
	char	*res;

	i = 0;
	if (s == 0)
		return ((char *)s);
	l = ft_strlen(s);
	res = (char *)ft_calloc(sizeof(char), l + 1);
	if (res == NULL)
		return (NULL);
	while (i < l)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
