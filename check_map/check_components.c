/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:25:55 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/23 15:25:56 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_components(t_map *map)
{
	map->players = 0;
	map->exits = 0;
	map->collectibles = 0;
}

static int	handle_cell(t_map *map, int x, int y)
{
	char	c;

	c = map->grid[y][x];
	if (c == 'P')
	{
		map->players++;
		map->player_x = x;
		map->player_y = y;
	}
	else if (c == 'E')
		map->exits++;
	else if (c == 'C')
		map->collectibles++;
	else if (c != '0' && c != '1')
	{
		print_error("Error: Invalid character in map");
		return (0);
	}
	return (1);
}

int	check_components(t_map *map)
{
	int	x;
	int	y;

	init_components(map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!handle_cell(map, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (map->players != 1)
		return (print_error("Error: Map must have exactly 1 player"), 0);
	if (map->exits != 1)
		return (print_error("Error: Map must have exactly 1 exit"), 0);
	if (map->collectibles < 1)
		return (print_error("Error: Map must have at least 1 collectible"), 0);
	return (1);
}

// #include "so_long.h"

// static void	init_components(t_map *map)
// {
// 	map->players = 0;
// 	map->exits = 0;
// 	map->collectibles = 0;
// }

// static int	handle_cell(t_map *map, int x, int y)
// {
// 	char	c;

// 	c = map->grid[y][x];
// 	if (c == 'P')
// 	{
// 		map->players++;
// 		map->player_x = x;
// 		map->player_y = y;
// 	}
// 	else if (c == 'E')
// 		map->exits++;
// 	else if (c == 'C')
// 		map->collectibles++;
// 	else if (c != '0' && c != '1')
// 	{
// 		print_error("Error: Invalid character in map");
// 		return (0);
// 	}
// 	return (1);
// }

// int	check_components(t_map *map)
// {
// 	int	x;
// 	int	y;

// 	init_components(map);
// 	y = 0;
// 	while (y < map->height)
// 	{
// 		if ((int)ft_strlen(map->grid[y]) != map->width)
// 			return (print_error("Error: Map is not rectangular"), 0);
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			if (!handle_cell(map, x, y))
// 				return (0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (map->players != 1)
// 		return (print_error("Error: Map must have exactly 1 player"), 0);
// 	if (map->exits != 1)
// 		return (print_error("Error: Map must have exactly 1 exit"), 0);
// 	if (map->collectibles < 1)
// 		return (print_error("Error: Map must have at least 1 collectible"), 0);
// 	return (1);
// }
