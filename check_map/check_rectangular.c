/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:26:06 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/23 15:39:33 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_map *map)
{
	int	i;
	int	len;

	if (!map || !map->grid || map->height == 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->grid[i]);
		if (len == 0)
		{
			print_error("Error: Empty line in map");
			return (0);
		}
		if (len != map->width)
		{
			print_error("Error: Map is not rectangular");
			return (0);
		}
		i++;
	}
	return (1);
}
