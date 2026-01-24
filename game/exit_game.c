#include "so_long.h"

void	exit_game(t_game *g)
{
	if (g->tex.wall)
		mlx_destroy_image(g->mlx, g->tex.wall);
	if (g->tex.floor)
		mlx_destroy_image(g->mlx, g->tex.floor);
	if (g->tex.player)
		mlx_destroy_image(g->mlx, g->tex.player);
	if (g->tex.collectible)
		mlx_destroy_image(g->mlx, g->tex.collectible);
	if (g->tex.exit)
		mlx_destroy_image(g->mlx, g->tex.exit);
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
