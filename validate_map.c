#include "so_long.h"

int	validate_map(t_map *map)
{
	if (!check_rectangular(map))
		return (0);
	if (!check_walls(map))
		return (0);
	if (!check_components(map))
		return (0);
	if (!check_path(map))
		return (0);
	return (1);
}

int	parse_map(char *filename, t_game *game)
{
	if (!read_map(filename, &game->map))
	{
		print_error("Error: Failed to read map file");
		return (0);
	}
	if (!validate_map(&game->map))
	{
		free_map(&game->map);
		return (0);
	}
	game->collected = 0;
	game->moves = 0;
	return (1);
}
