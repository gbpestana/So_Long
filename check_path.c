#include "so_long.h"

// Cria uma cópia do mapa para flood fill
static char **copy_map(t_map *map)
{
    char    **copy;
    int     i;

    if (!map || !map->grid)
        return (NULL);

    copy = (char **)malloc(sizeof(char *) * (map->height + 1));
    if (!copy)
        return (NULL);
    
    i = 0;
    while (i < map->height)
    {
        copy[i] = ft_strdup(map->grid[i]);
        if (!copy[i])
        {
            // Libera o que já foi alocado
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

// Libera a cópia do mapa
static void free_copy(char **copy, t_map *map)
{
    int i;

    if (!copy)
        return;
    i = 0;
    while (i < map->height)
    {
        if (copy[i])
            free(copy[i]);
        i++;
    }
    free(copy);
}

static void flood_fill(char **map_copy, int x, int y, int w, int h)
{
	if (x < 0 || x >= w || y < 0 || y >= h)
		return;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return;
	if (map_copy[y][x] == 'E')
	{
		map_copy[y][x] = 'V';
		return;
	}
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y, w, h);
	flood_fill(map_copy, x - 1, y, w, h);
	flood_fill(map_copy, x, y + 1, w, h);
	flood_fill(map_copy, x, y - 1, w, h);
}

// Verifica se existe caminho válido para todos os C e E
int check_path(t_map *map)
{
    char    **map_copy;
    int     x;
    int     y;
    int     reachable_c;
    int     reachable_e;

    if (!map || !map->grid || map->height <= 0 || map->width <= 0)
    {
        print_error("Error: Invalid map structure for path checking");
        return (0);
    }

    // Cria cópia do mapa
    map_copy = copy_map(map);
    if (!map_copy)
    {
        print_error("Error: Failed to create map copy for path validation");
        return (0);
    }

    // Executa flood fill a partir da posição do jogador
    flood_fill(map_copy, map->player_x, map->player_y, map->width, map->height);

    // Verifica se todos os C e E foram alcançados
    reachable_c = 0;
    reachable_e = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->grid[y][x] == 'C' && map_copy[y][x] == 'V')
                reachable_c++;
            if (map->grid[y][x] == 'E' && map_copy[y][x] == 'V')
                reachable_e++;
            x++;
        }
        y++;
    }

    free_copy(map_copy, map);

    // Valida se todos foram alcançados
    if (reachable_c != map->collectibles)
    {
        print_error("Error: Not all collectibles are reachable");
        return (0);
    }
    if (reachable_e != 1)
    {
        print_error("Error: Exit is not reachable");
        return (0);
    }

    return (1);
}
