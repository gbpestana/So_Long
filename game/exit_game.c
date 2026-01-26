#include "so_long.h"

void	exit_game(t_game *g)
{
	destroy_textures(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	free_map(&g->map);
	exit(0);
}

int	handle_close(t_game *g)
{
	exit_game(g);
	return (0);
}
