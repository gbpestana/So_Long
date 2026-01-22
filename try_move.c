#include "so_long.h"

void	try_move(t_game *g, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target;

	new_x = g->map.player_x + dx;
	new_y = g->map.player_y + dy;

	if (new_x < 0 || new_y < 0
		|| new_x >= g->map.width || new_y >= g->map.height)
		return ;

	target = g->map.grid[new_y][new_x];

	if (target == '1')
		return ;

	if (target == 'E' && g->collected < g->map.collectibles)
		return ;

	if (target == 'C')
		g->collected++;

	/* limpa posição antiga */
	if (g->map.grid[g->map.player_y][g->map.player_x] != 'E')
		g->map.grid[g->map.player_y][g->map.player_x] = '0';

	/* move player */
	if (target != 'E')
		g->map.grid[new_y][new_x] = 'P';

	g->map.player_x = new_x;
	g->map.player_y = new_y;
	g->moves++;

	write(1, "Moves: ", 7);
	ft_putnbr_fd(g->moves, 1);
	write(1, "\n", 1);

	if (target == 'E' && g->collected == g->map.collectibles)
	{
		write(1, "You win!\n", 9);
		mlx_destroy_window(g->mlx, g->win);
		free_map(&g->map);
		exit(0);
	}
}
