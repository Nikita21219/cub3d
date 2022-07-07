#include "../../includes/cub3D.h"

unsigned int	get_pixel(t_pict_dt *img, unsigned x, unsigned y)
{
	return (*(unsigned *)(img->addr + (y * img->line_l + x * (img->bpp / 8))));
}

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
					my_mlx_pixel_put(data.mlx, pix, y, get_pixel(data.pict->no_wall, SCALE * (data.ray->x / SCALE - (float)(int)(data.ray->x / SCALE)), SCALE * (y - (WIN_Y / 2 - line)) / psh));
				else
					my_mlx_pixel_put(data.mlx, pix, y, get_pixel(data.pict->so_wall, SCALE * (data.ray->x / SCALE - (float)(int)(data.ray->x / SCALE)), SCALE * (y - (WIN_Y / 2 - line)) / psh));
			}
			else
			{
				if (data.ray->s == 'w')

					my_mlx_pixel_put(data.mlx, pix, y, get_pixel(data.pict->we_wall, SCALE * (data.ray->y / SCALE - (float)(int)(data.ray->y / SCALE)), SCALE * (y - (WIN_Y / 2 - line)) / psh));
				else
					my_mlx_pixel_put(data.mlx, pix, y, get_pixel(data.pict->ea_wall, SCALE * (data.ray->y / SCALE - (float)(int)(data.ray->y / SCALE)), SCALE * (y - (WIN_Y / 2 - line)) / psh));
			}
		}
		y++;
	}
}
