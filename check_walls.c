#include "so_long.h"

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
		{
			print_error("Error: Walls (top/bottom)");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
		{
			print_error("Error: Walls (sides)");
			return (0);
		}
		i++;
	}
	return (1);
}
