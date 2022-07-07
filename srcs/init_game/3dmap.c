#include "../../includes/cub3D.h"

unsigned int	get_pixel(t_pict_dt *img, float x, float y, int psh)
{
	unsigned int	ax;
	unsigned int	ay;

	ay = SCALE * (y - (WIN_Y / 2 - psh / 2)) / psh;
	ax = SCALE * (x / SCALE - (float)(int)(x / SCALE));
	return (*(unsigned *)(img->addr + \
	(ay * img->line_l + ax * (img->bpp / 8))));
}

void	map3d_draw(t_data data, int pix)
{
	int	proj_plane_dist;
	int	psh;
	int	line;
	int	y;

	proj_plane_dist = (WIN_X / 2) / tan((FOV / 2) * M_PI / 180);
	psh = fabsf(SCALE / data.ray->len_ray * proj_plane_dist);
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
					my_mlx_pixel_put(data.mlx, pix, y, \
					get_pixel(data.pict->no_wall, data.ray->x, y, psh));
				else
					my_mlx_pixel_put(data.mlx, pix, y, \
					get_pixel(data.pict->so_wall, data.ray->x, y, psh));
			}
			else
			{
				if (data.ray->s == 'w')

					my_mlx_pixel_put(data.mlx, pix, y, \
					get_pixel(data.pict->we_wall, data.ray->y, y, psh));
				else
					my_mlx_pixel_put(data.mlx, pix, y, \
					get_pixel(data.pict->ea_wall, data.ray->y, y, psh));
			}
		}
		y++;
	}
}
