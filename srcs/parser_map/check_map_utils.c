#include "../includes/cub3D.h"

int	check_rgb_range(t_data *data, int number)
{
	if (number < 0 || number > 255)
		ft_exit(data, WRONG_MAP);
	return (number);
}

int	convert_grb(char *str, t_data *data)
{
	char	**split;
	int		res;

	if (str == NULL)
		ft_exit(data, MALLOC_ERR);
	split = ft_split(str, ',');
	if (split == NULL)
		ft_exit(data, MALLOC_ERR);
	if (len_arr(split) != 3)
		ft_exit(data, WRONG_MAP);
	res = check_rgb_range(data, ft_atoi(split[0])) << 16 | \
		check_rgb_range(data, ft_atoi(split[1])) << 8 | \
		check_rgb_range(data, ft_atoi(split[2]));
	free_arr(split);
	return (res);
}

int	check_char(char c, t_data *data, float x, float y)
{
	int	flag;

	flag = 0;
	if (c != '0' && c != '1' && c != 'N' && \
	c != 'S' && c != 'E' && c != 'W' && c != ' ' && c != 'e')
		ft_exit(data, WRONG_MAP);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		flag++;
		if (c == 'N')
			data->pl->dir = (float)NO;
		else if (c == 'S')
			data->pl->dir = 1.5 * (float)SO;
		else if (c == 'W')
			data->pl->dir = (float)WE;
		else if (c == 'E')
			data->pl->dir = (float)EA;
		data->pl->x = (x * SCALE) + SCALE / 2;
		data->pl->y = (y * SCALE) + SCALE / 2;
	}
	return (flag);
}

void	check_only_walls(t_data *dt, char *str)
{
	while (*str)
	{
		if (*str != '1' && !ft_space(*str))
			ft_exit(dt, WRONG_MAP);
		str++;
	}
}

void	check_line(t_data *dt, char *str, int i)
{
	if (i == 0 || i + 1 == len_arr(dt->map))
		check_only_walls(dt, str);
	else
	{
		if (!startswith(str, "1"))
			ft_exit(dt, WRONG_MAP);
		if (!endswith(str, "1"))
			ft_exit(dt, WRONG_MAP);
	}
}

void	check_map(t_data *data)
{
	int	i;
	int	j;
	int	hero;

	i = -1;
	hero = 0;
	while (data->map[++i])
	{
		check_line(data, data->map[i], i);
		j = -1;
		while (data->map[i][++j])
		{
			if (ft_space(data->map[i][j]))
				check_space(data, i, j);
			if (data->map[i][j] == '0')
				check_zero(data, i, j);
			hero += check_char(data->map[i][j], data, (float) j, (float) i);
		}
	}
	if (hero != 1)
		ft_exit(data, WRONG_MAP);
}
