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

	i = ft_strlen(str) - 1;
	while (str[i] && ft_space(str[i]))
		i--;
	j = ft_strlen(end) - 1;
	while (str[i] && end[j])
		if (str[i--] != end[j--])
			return (0);
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
