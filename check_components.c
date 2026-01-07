#include "so_long.h"

int	check_components(t_map *map)
{
	int	x;
	int	y;

	map->players = 0;
	map->exits = 0;
	map->collectibles = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->players++;
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->grid[y][x] == 'E')
				map->exits++;
			else if (map->grid[y][x] == 'C')
				map->collectibles++;
			else if (map->grid[y][x] != '0' && map->grid[y][x] != '1')
			{
				print_error("Error: Invalid character in map");
				return (0);
			}
			x++;
		}
		y++;
	}
	if (map->players != 1)
	{
		print_error("Error: Map must have exactly 1 player (P)");
		return (0);
	}
		if (map->exits != 1)
	{
		print_error("Error: Map must have exactly 1 exit (E)");
		return (0);
	}
		if (map->collectibles < 1)
	{
		print_error("Error: Map must have at least 1 collectible (C)");
		return (0);
	}
	return (1);
}
