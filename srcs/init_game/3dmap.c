#include "../../includes/cub3D.h"

void	map3d_draw(t_data data, int pix)
{
	int	proj_plane_dist;
	int	psh;
	int	line;
	int	y;

	proj_plane_dist = (WIN_X / 2) / tan((FOV / 2) * M_PI / 180);
	psh = fabsf(SCALE / data.ray->len_ray * proj_plane_dist); //высота столбца
	line = psh / 2;
	y = 0;
	while (y < WIN_Y)
	{
		if (y <= (WIN_Y / 2 - line))
			my_mlx_pixel_put(data.mlx, pix, y, data.pict->ceiling);
		else if (y >= WIN_Y / 2 + line)
			my_mlx_pixel_put(data.mlx, pix, y, data.pict->floor);
		else
		{
			if (data.ray->s_x == 1)
			{
				if (data.ray->s == 'n')
					my_mlx_pixel_put(data.mlx, pix, y, 0x808000);
				else
					my_mlx_pixel_put(data.mlx, pix, y, 0x38c98f);

			}
			else
			{
				if (data.ray->s == 'w')
					my_mlx_pixel_put(data.mlx, pix, y, 0x0000FF);
				else
					my_mlx_pixel_put(data.mlx, pix, y, 0xd48422);
			}
		}
		y++;
	}
}
