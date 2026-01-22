#include "so_long.h"

int	handle_input(t_game *game)
{
	char	c;

	printf("Move (w/a/s/d, q to quit): ");
	if (scanf(" %c", &c) != 1)
		return (0);

	if (c == 'w')
		try_move(game, 0, -1);
	else if (c == 's')
		try_move(game, 0, 1);
	else if (c == 'a')
		try_move(game, -1, 0);
	else if (c == 'd')
		try_move(game, 1, 0);
	else if (c == 'q')
		return (0);

	return (1);
}
