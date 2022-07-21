/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:23 by bclarind          #+#    #+#             */
/*   Updated: 2022/07/21 15:49:24 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	startswith(char *str, char *start)
{
	while (*str && ft_space(*str))
		str++;
	if (ft_strnstr(str, start, ft_strlen(start)) == NULL)
		return (0);
	return (1);
}

int	endswith(char *str, char *end)
{
	int	i;
	int	j;

	if (str == NULL || end == NULL)
		return (1);
	i = ft_strlen(str) - 1;
	while (str[i] && ft_space(str[i]))
		i--;
	j = ft_strlen(end) - 1;
	while (i >= 0 && j >= 0)
	{
		if (str[i--] != end[j--])
			return (0);
	}
	return (1);
}

int	equal(char *f_str, char *s_str)
{
	int	i;

	if (!f_str || !s_str)
		return (0);
	if (ft_strlen(f_str) != ft_strlen(s_str))
		return (0);
	i = -1;
	while (f_str[++i])
		if (f_str[i] != s_str[i])
			return (0);
	return (1);
}
