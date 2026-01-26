/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:51:53 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/26 10:51:54 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *g)
{
	int		x;
	int		y;
	char	tile;

	mlx_clear_window(g->mlx, g->win);
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			tile = g->map.grid[y][x];

			mlx_put_image_to_window(g->mlx, g->win,
				g->tex.floor, x * TILE_SIZE, y * TILE_SIZE);

			if (tile == '1')
				mlx_put_image_to_window(g->mlx, g->win,
					g->tex.wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'P')
				mlx_put_image_to_window(g->mlx, g->win,
					g->tex.player, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
				mlx_put_image_to_window(g->mlx, g->win,
					g->tex.collectible, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'E')
				mlx_put_image_to_window(g->mlx, g->win,
					g->tex.exit, x * TILE_SIZE, y * TILE_SIZE);

			x++;
		}
		y++;
	}
	render_moves(g);
}


// void	render_map(t_game *g)
// {
// 	int		x;
// 	int		y;
// 	char	tile;

// 	y = 0;
// 	while (y < g->map.height)
// 	{
// 		x = 0;
// 		while (x < g->map.width)
// 		{
// 			tile = g->map.grid[y][x];

// 			// 1️⃣ SEMPRE desenha o chão
// 			mlx_put_image_to_window(
// 				g->mlx,
// 				g->win,
// 				g->tex.floor,
// 				x * TILE_SIZE,
// 				y * TILE_SIZE
// 			);

// 			// 2️⃣ Desenha o que estiver por cima
// 			if (tile == '1')
// 				mlx_put_image_to_window(g->mlx, g->win,
// 					g->tex.wall, x * TILE_SIZE, y * TILE_SIZE);
// 			else if (tile == 'P')
// 				mlx_put_image_to_window(g->mlx, g->win,
// 					g->tex.player, x * TILE_SIZE, y * TILE_SIZE);
// 			else if (tile == 'C')
// 				mlx_put_image_to_window(g->mlx, g->win,
// 					g->tex.collectible, x * TILE_SIZE, y * TILE_SIZE);
// 			else if (tile == 'E')
// 				mlx_put_image_to_window(g->mlx, g->win,
// 					g->tex.exit, x * TILE_SIZE, y * TILE_SIZE);

// 			x++;
// 		}
// 		y++;
// 	}
// 	render_moves(g);
// }
