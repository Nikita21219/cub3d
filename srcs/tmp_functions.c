#include "../includes/cub3D.h"

void	print_arr(char	**arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
		printf("%s\n", arr[i]);
}
