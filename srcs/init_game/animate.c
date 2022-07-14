#include "../../includes/cub3D.h"

void	animate(t_data *data)
{
	static int	i = 0;

	if (i % 2 == 0 && i % 4 != 0)
		data->sprite->pict_num = 1;
	else if (i % 4 == 0)
		data->sprite->pict_num = 2;
	i++;
}
