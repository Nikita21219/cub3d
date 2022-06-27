#include "../../includes/cub3D.h"

void	draw_square(t_data *data, float x, float y)
{
	float	tmp;
	float	tmp2;
	float	tmp3;

	tmp3 = y + 7;
	while (y < tmp3)
	{
		tmp = x;
		tmp2 = tmp + 7;
		while (tmp < tmp2)
		{
			printf("test\n");
			my_mlx_pixel_put(data->mlx, tmp++, y, 0x00FF000);
		}
		y++;
	}
}
