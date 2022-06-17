#include "../includes/cub3D.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
	}
	if (arr)
		free(arr);
	arr = NULL;
}

void	free_pict(t_data *data)
{
	if (data && data->pict)
	{
		if (data->pict->ea_wall)
		{
			free(data->pict->ea_wall);
			data->pict->ea_wall = NULL;
		}
		if (data->pict->no_wall)
		{
			free(data->pict->no_wall);
			data->pict->no_wall = NULL;
		}
		if (data->pict->so_wall)
		{
			free(data->pict->so_wall);
			data->pict->so_wall = NULL;
		}
		if (data->pict->we_wall)
		{
			free(data->pict->we_wall);
			data->pict->we_wall = NULL;
		}
	}
}
