#include "../../includes/cub3D.h"

int	allow_ch(char c)
{
	if (c == '1' || c == ' ')
		return (1);
	return (0);
}

void	left_top_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j + 1]) || \
	!allow_ch(dt->map[i + 1][j]) || \
	!allow_ch(dt->map[i + 1][j + 1]))
		ft_exit(dt, WRONG_MAP);
}

void	right_top_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i + 1][j]) || \
	!allow_ch(dt->map[i + 1][j - 1]))
		ft_exit(dt, WRONG_MAP);
}

void	left_bot_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j + 1]) || \
	!allow_ch(dt->map[i - 1][j + 1]) || \
	!allow_ch(dt->map[i - 1][j]))
		ft_exit(dt, WRONG_MAP);
}

void	right_bot_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i - 1][j - 1]) || \
	!allow_ch(dt->map[i - 1][j]))
		ft_exit(dt, WRONG_MAP);
}

void	left_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i - 1][j]) || \
	!allow_ch(dt->map[i - 1][j + 1]) || \
	!allow_ch(dt->map[i][j + 1]) || \
	!allow_ch(dt->map[i + 1][j + 1]) || \
	!allow_ch(dt->map[i + 1][j]))
		ft_exit(dt, WRONG_MAP);
}

void	right_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i - 1][j]) || \
	!allow_ch(dt->map[i - 1][j - 1]) || \
	!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i + 1][j - 1]) || \
	!allow_ch(dt->map[i + 1][j]))
		ft_exit(dt, WRONG_MAP);
}

void	bottom_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i - 1][j - 1]) || \
	!allow_ch(dt->map[i - 1][j]) || \
	!allow_ch(dt->map[i - 1][j + 1]) || \
	!allow_ch(dt->map[i][j + 1]))
		ft_exit(dt, WRONG_MAP);
}

void	top_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i + 1][j - 1]) || \
	!allow_ch(dt->map[i + 1][j]) || \
	!allow_ch(dt->map[i + 1][j + 1]) || \
	!allow_ch(dt->map[i][j + 1]))
		ft_exit(dt, WRONG_MAP);
}

void	other_space_handle(t_data *dt, int i, int j)
{

	// if (j - 1 <= (int)ft_strlen(dt->map[i - 1]))
	// printf("j - 1 = %d, (int)ft_strlen(dt->map[i - 1]) = %d\n\n", j - 1, (int)ft_strlen(dt->map[i - 1]));

	// printf("test1 i=%d, j=%d\n", i, j);
	// printf("%c\n", dt->map[i - 1][j - 1]);
	// printf("test2\n\n");

	if ((j - 1 <= (int)ft_strlen(dt->map[i - 1]) && !allow_ch(dt->map[i - 1][j - 1])) || \
	(j <= (int)ft_strlen(dt->map[i - 1]) && !allow_ch(dt->map[i - 1][j])) || \
	(j <= (int)ft_strlen(dt->map[i - 1]) && !allow_ch(dt->map[i - 1][j + 1])) || \
	(j + 1 <= (int)ft_strlen(dt->map[i]) && !allow_ch(dt->map[i][j + 1])) || \
	(j + 1 <= (int)ft_strlen(dt->map[i + 1]) && !allow_ch(dt->map[i + 1][j + 1])) || \
	(j <= (int)ft_strlen(dt->map[i + 1]) && !allow_ch(dt->map[i + 1][j])) || \
	(j - 1 <= (int)ft_strlen(dt->map[i + 1]) && !allow_ch(dt->map[i + 1][j - 1])) || \
	(j - 1 <= (int)ft_strlen(dt->map[i]) && !allow_ch(dt->map[i][j - 1])))
		ft_exit(dt, WRONG_MAP);
}

void	check_space(t_data *dt, int i, int j)
{
	if (i == 0 && j == 0)
		left_top_space_handle(dt, i, j);
	else if (i == 0 && j == (int) ft_strlen(dt->map[i]) - 1)
		right_top_space_handle(dt, i, j);
	else if (i == len_arr(dt->map) - 1 && j == 0)
		left_bot_space_handle(dt, i, j);
	else if (i == len_arr(dt->map) - 1 && j == (int) ft_strlen(dt->map[i]) - 1)
		right_bot_space_handle(dt, i, j);
	else if (j == 0)
		left_space_handle(dt, i, j);
	else if (j == (int) ft_strlen(dt->map[i]) - 1)
		right_space_handle(dt, i, j);
	else if (i == len_arr(dt->map) - 1)
		bottom_space_handle(dt, i, j);
	else if (i == 0)
		top_space_handle(dt, i, j);
	else
		other_space_handle(dt, i, j);
}
