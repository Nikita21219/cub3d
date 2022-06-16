/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:31:33 by rrast             #+#    #+#             */
/*   Updated: 2022/03/21 19:50:10 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	lensrc;
	size_t	i;

	dst = 0;
	i = 0;
	if (s == NULL)
		return (ft_strdup(""));
	lensrc = ft_strlen(s);
	if (start >= lensrc || len == 0)
		return (ft_strdup(""));
	if (len > lensrc)
		len = lensrc;
	dst = malloc(sizeof(char) * len + 1);
	if (dst == NULL)
		return (NULL);
	while (len-- && s[start])
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
