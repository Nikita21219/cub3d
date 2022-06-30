#include "../includes/cub3D.h"

int	len_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	get_map_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i - 6);
}
