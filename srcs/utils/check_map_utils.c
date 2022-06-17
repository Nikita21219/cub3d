#include "../includes/cub3D.h"

int	get_map_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i - 6);
}

int	len_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	convert_grb(char *str, t_data *data)
{
	char	**split;

	if (str == NULL)
		ft_exit(data, MALLOC_ERR);
	split = ft_split(str, ',');
	if (split == NULL)
		ft_exit(data, MALLOC_ERR);
	if (len_arr(split) != 3)
		ft_exit(data, WRONG_MAP);
	return (ft_atoi(split[0]) << 16 | ft_atoi(split[1]) << 8 | ft_atoi(split[2]));
}

void	check_char(char c, t_data *data, float x, float y)
{
	static int	flag;

	flag = 0;
	if (c != '0' && c != '1' && c != 'N' && \
	c != 'S' && c != 'E' && c != 'W' && c != ' ' && c != '\t')
		ft_exit(data, WRONG_MAP);
	if (c == 'N' || c != 'S' || c != 'E' || c != 'W')
	{
		flag++;
		if (c == 'N')
			data->pl->dir = NO;
		else if (c == 'S')
			data->pl->dir = SO;
		else if (c == 'W')
			data->pl->dir = WE;
		else if (c == 'E')
			data->pl->dir = EA;
		data->pl->x = x * SCALE;
		data->pl->y = y * SCALE;
	}
	if (flag > 1)
		ft_exit(data, WRONG_MAP);
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			check_char(data->map[i][j], data, (float) j, (float) i);
		}
	}
	printf("x = %f y = %f\n", data->pl->x, data->pl->y);
}
