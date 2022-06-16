#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/includes/libft.h"

typedef struct s_data
{
	char			**map;
	struct s_pict	*pict;
	void			*mlx;
	void			*win;
}	t_data;

typedef struct s_pict
{
	void	*empty;
	void	*wall;
	void	*pl;
	void	*coll;
	void	*exit;
	void	*opex;
	void	*obst;
}	t_pict;

/* Parser map */

t_data	parser_map(char *name);

/* Utils */

void	ft_exit(t_data *data, int i);
int		gnl(int fd, t_data *data);
void	clearmap(char **map);

#endif