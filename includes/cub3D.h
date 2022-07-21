#ifndef CUB3D_H
# define CUB3D_H

# define NO		M_PI_2
# define WE		M_PI
# define SO		M_PI
# define EA		0.0
# define SCALE	64
# define SPEED	12
# define WIN_X	1920
# define WIN_Y	1080
# define FOV	60.0

# define WRONG_MAP_NAME	1
# define PATH_MAP_ERR	2
# define OPEN_MAP_ERR	3
# define WRONG_MAP		4
# define MALLOC_ERR		12

# define LEFT		0
# define RIGHT		2
# define UP			13
# define DOWN		1
# define ESC		53
# define TURN_LEFT	123
# define TURN_RIGHT	124

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

typedef struct s_mouse
{
	int			x;
	int			visible;
}	t_mouse;

typedef struct s_mlx {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_l;
	int			endian;
}	t_mlx;

typedef struct s_pict_dt {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_l;
	int			is_init;
	int			endian;
}	t_pict_dt;

typedef struct s_pict
{
	int			floor;
	int			ceiling;
	void		*pl;
	t_pict_dt	*no_wall;
	t_pict_dt	*so_wall;
	t_pict_dt	*we_wall;
	t_pict_dt	*ea_wall;
	t_pict_dt	*sprite1;
	t_pict_dt	*sprite2;
	t_pict_dt	*door;
}	t_pict;

typedef struct s_pl
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}	t_pl;

typedef struct s_ray
{
	float		x;
	float		y;
	float		s_x;
	float		s_y;
	float		len_ray;
	int			door;
	char		s;
}	t_ray;

typedef struct s_sprite
{
	int				dx;
	float			x;
	float			y;
	float			len;
	float			dir;
	void			*img;
	int				pict_num;
	struct s_sprite	*next;
}	t_sprite;

typedef struct s_moves
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			turn_left;
	int			turn_right;
}	t_moves;

typedef struct s_data
{
	char		**map;
	t_pict		*pict;
	t_pl		*pl;
	t_mlx		*mlx;
	t_ray		*ray;
	t_mouse		*mouse;
	t_sprite	*sprite;
	t_sprite	*door;
	t_moves		*moves;
	float		*n_ray;
	int			proj_plane_dist;
}	t_data;

/* Parser map */

void			check_mapfile(t_data *data);
void			parser_map(t_data *data, char *name);
int				allow_ch(char c);
void			left_top_space_handle(t_data *dt, int i, int j);
void			right_top_space_handle(t_data *dt, int i, int j);
void			left_bot_space_handle(t_data *dt, int i, int j);
void			right_bot_space_handle(t_data *dt, int i, int j);
void			bottom_space_handle(t_data *dt, int i, int j);
void			check_zero(t_data *dt, int i, int j);
int				is_not_path(char *str);
void			check_door(t_data *dt, int i, int j);
void			init_data_addr(t_data *data);
int				is_identifier(char *str);
void			check_null_img(t_data *data, void *ptr);
void			init_pict(char *str, t_data *data, int *roof, int *floor);
void			init_pict_pointers(t_data *data);
void			check_null_img2(t_data *data);


/* Game and window */

void			ft_init_window(t_data *data);
void			draw_map(t_data *data);

/* Utils */

void			ft_exit(t_data *data, int i);
void			gnl(int fd, t_data *data);
void			clearmap(char **map);
int				exit_with_print(char *err_str);
int				startswith(char *str, char *start);
int				ft_space(char c);
int				equal(char *f_str, char *s_str);
int				get_map_size(char **arr);
int				convert_grb(char *str, t_data *data);
int				len_arr(char **arr);
void			check_map(t_data *data);
int				endswith(char *str, char *end);
void			check_space(t_data *dt, int i, int j);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void			draw_square(t_data *data, float x, float y);
void			draw_block(t_mlx *mlx, int x, int y, int color);
void			map3d_draw(t_data data, int pix);
float			len_vector(t_data data, float x, float y);

/* Raycast */

void			check_len_ray(t_ray hor, t_ray ver, t_data *data, float angle);
int				check_wall(t_ray *hv, char **map, int *wall);
void			rays(t_data *data, float angle);

/*Sprites*/

unsigned int	get_pixel(t_pict_dt *img, float x, float y, int psh);
void			init_sprites(t_data *data);
void			draw_sprite(t_data *data, t_sprite *sprite, float *len_wall);
void			sort_sprites(t_sprite *sprite);
void			animate(t_data *data);
unsigned int	get_color(t_pict_dt *img, float x, float y);

/* Free utils */

void			free_arr(char **arr);

/*Moves*/

int				ft_exitbut(t_data *data);
int				mouse(t_data *data);
int				ft_press(int key, t_data *data);
int				ft_release(int key, t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			move_up(t_data *data);
void			move_down(t_data *data);
void			around_left(t_data *data);
void			around_right(t_data *data);
int				mouse_visible(int button, int x, int y, t_data *data);

/*TMP*/

void	print_arr(char	**arr);

#endif