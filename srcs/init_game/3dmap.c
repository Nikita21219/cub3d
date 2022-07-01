#include "../../includes/cub3D.h"

void	map3d_draw(t_data data, int pix)
{
	int	proj_plane_dist;
	int	psh;
	int	line;
	int	y;

	proj_plane_dist = (WIN_X / 2) / tan((FOV / 2) * M_PI / 180);
	psh = SCALE / data.ray->len_ray * proj_plane_dist; //высота столбца
	// printf("proj_plane_dist=%d, len_ray=%f\n", proj_plane_dist, data.ray->len_ray);
	// if (psh == 290)
	// 	printf("\n\n<<<<<<proj_plane_dist=%d, len_ray=%f>>>>>>\n\n", proj_plane_dist, data.ray->len_ray);
	line = psh / 2;
	y = 0;
	while (y < WIN_Y)
	{
		if (y < (WIN_Y / 2 - line))
			my_mlx_pixel_put(data.mlx, pix, y, data.pict->ceiling);
		else if (y > WIN_Y / 2 + line)
			my_mlx_pixel_put(data.mlx, pix, y, data.pict->floor);
		else
			my_mlx_pixel_put(data.mlx, pix, y, 0xC0C0C0);
		y++;
	}
}
