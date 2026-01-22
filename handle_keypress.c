#include "so_long.h"

int	handle_keypress(int keycode, t_game *g)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		try_move(g, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		try_move(g, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		try_move(g, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		try_move(g, 1, 0);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(g->mlx, g->win);
		free_map(&g->map);
		exit(0);
	}
	render_map(g);
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(&game->map);
	exit(0);
}
