/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:28:33 by rrast             #+#    #+#             */
/*   Updated: 2022/04/25 20:03:58 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_left(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

static size_t	ft_right(char const *s1, char const *set, size_t len)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (s1[len] == set[j])
		{
			j = 0;
			len--;
		}
		else
			j++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*dst;

	if (s1 == 0)
		return (ft_strdup(""));
	if (set == 0)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	i = ft_left(s1, set);
	if (i == len)
		return (ft_strdup(""));
	j = ft_right(s1, set, len - 1);
	dst = ft_substr(s1, i, j - i + 1);
	return (dst);
}
