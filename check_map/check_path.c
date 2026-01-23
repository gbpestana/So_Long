/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:26:00 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/23 15:38:38 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

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

static void	free_copy(char **copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (copy[i])
			free(copy[i]);
		i++;
	}
	free(copy);
}

static void	flood_fill(char **map_copy, int x, int y, t_map *m)
{
	if (x < 0 || x >= m->width || y < 0 || y >= m->height)
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'E')
	{
		map_copy[y][x] = 'V';
		return ;
	}
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y, m);
	flood_fill(map_copy, x - 1, y, m);
	flood_fill(map_copy, x, y + 1, m);
	flood_fill(map_copy, x, y - 1, m);
}

static void	count_reachable(t_map *map, char **copy,
	int *c_count, int *e_count)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'C' && copy[y][x] == 'V')
				(*c_count)++;
			if (map->grid[y][x] == 'E' && copy[y][x] == 'V')
				(*e_count)++;
			x++;
		}
		y++;
	}
}

int	check_path(t_map *map)
{
	char	**copy;
	int		reach_c;
	int		reach_e;

	copy = copy_map(map);
	if (!copy)
		return (print_error("Error: Map copy failed"), 0);
	flood_fill(copy, map->player_x, map->player_y, map);
	reach_c = 0;
	reach_e = 0;
	count_reachable(map, copy, &reach_c, &reach_e);
	free_copy(copy, map->height);
	if (reach_c != map->collectibles)
		return (print_error("Error: Not all collectibles reachable"), 0);
	if (reach_e != 1)
		return (print_error("Error: Exit not reachable"), 0);
	return (1);
}
