/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:28:06 by rrast             #+#    #+#             */
/*   Updated: 2022/03/17 12:40:25 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_kword(const char *s, size_t len, char c)
{
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (len != 0)
	{
		if ((char)s[i] != c)
		{
			k++;
			while ((char)s[i] != c && len)
			{
				i++;
				len--;
			}
		}
		while ((char)s[i] == c && len)
		{
			i++;
			len--;
		}
	}
	return (k);
}

static char	**ft_duostr(size_t *el, const char *s, char **dst)
{
	if (el[0] == 0 || el[2] == 0)
	{
		dst[el[1]] = NULL;
		return (dst);
	}
	dst[el[1]] = ft_strdup(s);
	if (dst[el[1]] == NULL)
		return (NULL);
	dst[el[1] + 1] = NULL;
	return (dst);
}

static char	**ft_free(char **dst, size_t *el)
{
	while (el[1])
	{
		free (dst[el[1]]);
		el[1]--;
	}
	free (dst);
	return (dst);
}

static char	**ft_wrtarr(size_t *el, const char *s, char **dst, char c)
{
	while (el[1] < el[2])
	{
		while ((char)s[el[3]] == c && s[el[3]])
			el[3]++;
		if ((char)s[el[3]] != c && s[el[3]])
		{
			el[0] = 0;
			while ((char)s[el[3]] != c && s[el[3]])
			{
				el[0]++;
				el[3]++;
			}
			dst[el[1]] = ft_substr(s, el[3] - el[0], el[0]);
			if (dst[el[1]] == NULL)
			{
				dst = ft_free(dst, el);
				return (NULL);
			}
		}
		el[1]++;
	}
	dst[el[1]] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	el[4];

	el[1] = 0;
	el[3] = 0;
	if (s == NULL)
		return (NULL);
	el[0] = ft_strlen(s);
	el[2] = ft_kword(s, el[0], c);
	dst = (char **)malloc(sizeof(char *) * (el[2] + 1));
	if (dst == NULL)
		return (NULL);
	if (c == '\0' || el[2] == 0 || el[0] == 0)
	{
		dst = ft_duostr(el, s, dst);
		return (dst);
	}
	dst = ft_wrtarr(el, s, dst, c);
	return (dst);
}
