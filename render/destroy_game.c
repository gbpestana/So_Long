/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:51:43 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/26 10:51:44 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_textures(t_game *g)
{
	if (g->tex.wall)
		mlx_destroy_image(g->mlx, g->tex.wall);
	if (g->tex.floor)
		mlx_destroy_image(g->mlx, g->tex.floor);
	if (g->tex.player)
		mlx_destroy_image(g->mlx, g->tex.player);
	if (g->tex.collectible)
		mlx_destroy_image(g->mlx, g->tex.collectible);
	if (g->tex.exit)
		mlx_destroy_image(g->mlx, g->tex.exit);
}
