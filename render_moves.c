#include "so_long.h"

void	render_moves(t_game *g)
{
	char	*str;
	char	*num;

	num = ft_itoa(g->moves);
	str = ft_strjoin("Moves: ", num);

	mlx_string_put(
		g->mlx,
		g->win,
		10, 20,
		0xFFFFFF,
		str
	);

	free(num);
	free(str);
}
