#ifndef CUB3D_H
# define CUB3D_H

# define NO		1
# define SO		2
# define WE		3
# define EA		4
# define SCALE	64


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
	char	*floor;
	char	*ceiling;
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
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}	t_pl;

/* Parser map */
t_data	parser_map(char *name);
void	check_mapfile(t_data *data);

/* Game and window */

void	ft_init_window(t_data *data);
void	draw_map(t_data *data);

/* Utils */
void	ft_exit(t_data *data, int i);
void	gnl(int fd, t_data *data);
void	clearmap(char **map);
int		exit_with_print(char *err_str);
int		startswith(char *str, char *start);
int		ft_space(char c);
int		equal(char *f_str, char *s_str);

/* Free utils */
void	free_arr(char **arr);

#endif