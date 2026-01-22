#include "so_long.h"

void	draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_pixel_put(
				game->mlx,
				game->win,
				x * TILE_SIZE + j,
				y * TILE_SIZE + i,
				color
			);
			j++;
		}
		i++;
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '1')
				draw_square(game, x, y, COLOR_WALL);
			else if (game->map.grid[y][x] == '0')
				draw_square(game, x, y, COLOR_FLOOR);
			else if (game->map.grid[y][x] == 'P')
				draw_square(game, x, y, COLOR_PLAYER);
			else if (game->map.grid[y][x] == 'E')
				draw_square(game, x, y, COLOR_EXIT);
			else if (game->map.grid[y][x] == 'C')
				draw_square(game, x, y, COLOR_COLLECT);
			x++;
		}
		y++;
	}
	render_moves(game);
}
