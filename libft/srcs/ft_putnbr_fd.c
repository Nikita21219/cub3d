/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:33:15 by rrast             #+#    #+#             */
/*   Updated: 2021/10/18 14:45:18 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_res_fd(int n, int a, int fd)
{
	size_t	k;
	int		i;
	int		g;

	k = 0;
	i = 0;
	while (n)
	{
		k = (k * 10) + ((n % 10) * a);
		n = n / 10;
		i++;
	}
	g = i;
	while (i > 0)
	{
		ft_putchar_fd((k % 10) + 48, fd);
		k = k / 10;
		i--;
	}
	return (g);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	a;
	int	i;

	a = 1;
	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		a = -1;
		i = 1;
	}
	i = i + ft_res_fd(n, a, fd);
	return (i);
}
