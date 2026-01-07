#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
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
	printf(" Map is VALID!\n");
	print_map(&game.map);
	free_map(&game.map);
	return (0);
}
