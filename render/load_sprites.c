/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:51:47 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/26 10:51:48 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_textures(t_game *g)
{
	if (!g->tex.wall || !g->tex.floor
		|| !g->tex.player || !g->tex.collectible || !g->tex.exit)
	{
		write(2, "Error: Failed to load textures\n", 31);
		exit_game(g);
	}
}

void	load_textures(t_game *g)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	g->tex.wall = mlx_xpm_file_to_image(g->mlx,
			"sprites/wall.xpm", &w, &h);
	g->tex.floor = mlx_xpm_file_to_image(g->mlx,
			"sprites/floor.xpm", &w, &h);
	g->tex.player = mlx_xpm_file_to_image(g->mlx,
			"sprites/player.xpm", &w, &h);
	g->tex.collectible = mlx_xpm_file_to_image(g->mlx,
			"sprites/collectible.xpm", &w, &h);
	g->tex.exit = mlx_xpm_file_to_image(g->mlx,
			"sprites/exit.xpm", &w, &h);
	check_textures(g);
}
