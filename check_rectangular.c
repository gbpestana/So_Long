#include "so_long.h"

int check_rectangular(t_map *map)
{
    int	i;
    int	len;

	if (!map || !map->grid || map->height == 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->grid[i]);
		if (len != map->width)
		{
			print_error("Error: Map is not rectangular");
			return (0);
		}
		i++;
	}
	return (1);
}
