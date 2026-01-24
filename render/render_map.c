#include "so_long.h"

static void	*get_tile_img(t_game *g, char tile)
{
	if (tile == '1')
		return (g->tex.wall);
	if (tile == '0')
		return (g->tex.floor);
	if (tile == 'P')
		return (g->tex.player);
	if (tile == 'C')
		return (g->tex.collectible);
	if (tile == 'E')
		return (g->tex.exit);
	return (NULL);
}

void	render_map(t_game *g)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			img = get_tile_img(g, g->map.grid[y][x]);
			if (img)
				mlx_put_image_to_window(
					g->mlx,
					g->win,
					img,
					x * TILE_SIZE,
					y * TILE_SIZE);
			x++;
		}
		y++;
	}
	render_moves(g);
}
