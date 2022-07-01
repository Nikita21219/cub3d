#ifndef CUB3D_H
# define CUB3D_H

# define NO		M_PI_2
# define WE		M_PI
# define SO		M_PI
# define EA		0.0
# define SCALE	64
# define SPEED	5
# define WIN_X	1920
# define WIN_Y	1080
# define FOV	60.0

# define WRONG_MAP_NAME	1
# define PATH_MAP_ERR	2
# define OPEN_MAP_ERR	3
# define WRONG_MAP		4
# define MALLOC_ERR		12

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

typedef struct s_data
{
	char			**map;
	struct s_pict	*pict;
	struct s_pl		*pl;
	struct s_mlx	*mlx;
	struct s_ray	*ray;
	int				win_x;
	int				win_y;
}	t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_pict
{
	int		floor;
	int		ceiling;
	void	*no_wall;
	void	*so_wall;
	void	*we_wall;
	void	*ea_wall;
	void	*pl;
	void	*door;
	void	*sprite;
}	t_pict;

typedef struct s_pl
{
	float			x;
	float			y;
	float			dx;
	float			dy;
	float			dir;
	float			start;
	float			end;
}	t_pl;

typedef struct s_ray
{
	float		x;
	float		y;
	float		s_x;
	float		s_y;
	float		len_ray;
}	t_ray;

/* Parser map */

void	check_mapfile(t_data *data);
void	parser_map(t_data *data, char *name);
int		allow_ch(char c);
void	left_top_space_handle(t_data *dt, int i, int j);
void	right_top_space_handle(t_data *dt, int i, int j);
void	left_bot_space_handle(t_data *dt, int i, int j);
void	right_bot_space_handle(t_data *dt, int i, int j);
void	bottom_space_handle(t_data *dt, int i, int j);
void	check_zero(t_data *dt, int i, int j);

/* Game and window */

void	ft_init_window(t_data *data);
void	draw_map(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);

/* Utils */

void	ft_exit(t_data *data, int i);
void	gnl(int fd, t_data *data);
void	clearmap(char **map);
int		exit_with_print(char *err_str);
int		startswith(char *str, char *start);
int		ft_space(char c);
int		equal(char *f_str, char *s_str);
int		get_map_size(char **arr);
int		convert_grb(char *str, t_data *data);
int		len_arr(char **arr);
void	check_map(t_data *data);
int		endswith(char *str, char *end);
void	check_space(t_data *dt, int i, int j);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	draw_square(t_data *data, float x, float y);
void	draw_block(t_mlx *mlx, int x, int y, int color);
void	map3d_draw(t_data data, int pix);

/* Raycast */

void	check_len_ray(t_ray hor, t_ray ver, t_data *data, float angle);
int		check_wall(t_ray *hv, char **map, int *wall);
void	rays(t_data *data, float angle);

/* Free utils */

void	free_arr(char **arr);

/*TMP*/

void	print_arr(char	**arr);

#endif