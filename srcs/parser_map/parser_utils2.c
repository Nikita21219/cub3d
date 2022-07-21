#include "../../includes/cub3D.h"

void	check_zero(t_data *dt, int i, int j)
{
	if (j >= (int)ft_strlen(dt->map[i + 1]) || \
	j >= (int)ft_strlen(dt->map[i - 1]))
		ft_exit(dt, WRONG_MAP);
}

void	check_door(t_data *dt, int i, int j)
{
	if (i > 0 && j > 0 && i < len_arr(dt->map) - 1 \
	&& j < (int)ft_strlen(dt->map[i + 1] - 1) && \
	dt->map[i - 1][j] == '1' && \
	dt->map[i][j + 1] == '1' && \
	dt->map[i + 1][j] == '1' && \
	dt->map[i][j - 1] == '1')
		ft_exit(dt, WRONG_MAP);
	if (!((dt->map[i + 1][j] == '1' && \
	dt->map[i - 1][j] == '1') || \
	((dt->map[i][j + 1] == '1' && \
	dt->map[i][j - 1] == '1'))))
		ft_exit(dt, WRONG_MAP);
}

/* 
11111111
10000001
10010001
101d1001
11111111
 */

int	is_not_path(char *str)
{
	(void) str;
	int	i;

	i = -1;
	while (str && str[++i])
		if (!ft_space(str[i]))
			return (0);
	return (1);
}
