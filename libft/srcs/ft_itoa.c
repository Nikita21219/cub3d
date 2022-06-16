/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:59:10 by rrast             #+#    #+#             */
/*   Updated: 2022/05/19 10:07:21 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_revmal(char *res, int n, int i, int a)
{
	if (a < 0)
		res = (char *)ft_calloc(sizeof(char), (i + 2));
	else
		res = (char *)ft_calloc(sizeof(char), (i + 1));
	if (res == NULL)
		return (NULL);
	if (a < 0)
	{
		res[0] = '-';
		i++;
	}
	i--;
	while (n)
	{
		res[i] = ((n % 10) * a) + 48;
		n = n / 10;
		i--;
	}
	return (res);
}

static int	ft_sizechar(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		a;
	char	*res;

	if (n == 0)
	{
		res = ft_strdup("0");
		if (res == NULL)
			return (NULL);
		return (res);
	}
	res = 0;
	if (n > 0)
		a = 1;
	else
		a = -1;
	i = ft_sizechar(n);
	res = ft_revmal(res, n, i, a);
	return (res);
}
