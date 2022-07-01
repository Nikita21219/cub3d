#include "../../includes/cub3D.h"

void	check_zero(t_data *dt, int i, int j)
{
	if (j > (int)ft_strlen(dt->map[i + 1]) || \
	j > (int)ft_strlen(dt->map[i - 1]))
		ft_exit(dt, WRONG_MAP);
}
