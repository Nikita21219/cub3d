/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:58:05 by rrast             #+#    #+#             */
/*   Updated: 2022/03/17 12:41:20 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*buf;

	if (c == 0)
		return (ft_strchr (s, '\0'));
	if (ft_strlen(s) == 0 || s == NULL)
		return (NULL);
	buf = 0;
	c = c % 256;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char) c)
			buf = (unsigned char *) s;
		s++;
	}
	return ((char *)buf);
}
