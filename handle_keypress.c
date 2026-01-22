#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_map(&game->map);
		exit(0);
	}
	else if (keycode == KEY_W)
		try_move(game, 0, -1);
	else if (keycode == KEY_S)
		try_move(game, 0, 1);
	else if (keycode == KEY_A)
		try_move(game, -1, 0);
	else if (keycode == KEY_D)
		try_move(game, 1, 0);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	render_map(game);
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(&game->map);
	exit(0);
}
