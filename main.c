#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->grid)
	{
		printf("Error: Invalid map structure\n");
		return;
	}
	while (i < map->height && map->grid[i])
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
}

void	init_game(t_game *game)
{
	game->collected = 0;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		print_error("Usage: ./so_long <map.ber>");
		return (1);
	}

	if (!parse_map(argv[1], &game))
	{
		print_error("Map validation failed!");
		return (1);
	}

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);

	game.win = mlx_new_window(
		game.mlx,
		game.map.width * TILE_SIZE,
		game.map.height * TILE_SIZE,
		"so_long"
	);

	render_map(&game);

	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);

	mlx_loop(game.mlx);

	// nunca chega aqui
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	if (argc != 2)
// 	{
// 		print_error("Usage: ./so_long <map.ber>");
// 		return (1);
// 	}
// 	game.map.grid = NULL;
// 	game.map.width = 0;
// 	game.map.height = 0;
// 	if (!parse_map(argv[1], &game))
// 	{
// 		print_error("Map validation failed!");
// 		return (1);
// 	}
// 	printf("Map is VALID!\n");
// 	print_map(&game.map);
// 	free_map(&game.map);
// 	return (0);
// }
