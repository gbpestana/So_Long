#include "so_long.h"

int	game_loop(t_game *g)
{
	g->frame_count++;

	if (g->frame_count < g->speed)
		return (0);
	g->frame_count = 0;

	if (g->input.up)
	{
		try_move(g, 0, -1);
		g->input.up = 0;
	}
	else if (g->input.down)
	{
		try_move(g, 0, 1);
		g->input.down = 0;
	}
	else if (g->input.left)
	{
		try_move(g, -1, 0);
		g->input.left = 0;
	}
	else if (g->input.right)
	{
		try_move(g, 1, 0);
		g->input.right = 0;
	}

	render_map(g);
	return (0);
}
