#include "../../includes/cub3D.h"

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

void	bottom_space_handle(t_data *dt, int i, int j)
{
	if (!allow_ch(dt->map[i][j - 1]) || \
	!allow_ch(dt->map[i - 1][j - 1]) || \
	!allow_ch(dt->map[i - 1][j]) || \
	!allow_ch(dt->map[i - 1][j + 1]) || \
	!allow_ch(dt->map[i][j + 1]))
		ft_exit(dt, WRONG_MAP);
}
