/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:26:42 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/23 15:26:43 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game *g, int x, int y)
{
	char	target;

	if (x < 0 || y < 0
		|| x >= g->map.width || y >= g->map.height)
		return (0);
	target = g->map.grid[y][x];
	if (target == '1')
		return (0);
	if (target == 'E' && g->collected < g->map.collectibles)
		return (0);
	return (1);
}

static void	update_player_position(t_game *g, int x, int y, char target)
{
	if (g->map.grid[g->map.player_y][g->map.player_x] != 'E')
		g->map.grid[g->map.player_y][g->map.player_x] = '0';
	if (target != 'E')
		g->map.grid[y][x] = 'P';
	g->map.player_x = x;
	g->map.player_y = y;
}

static void	print_moves(t_game *g)
{
	write(1, "Moves: ", 7);
	ft_putnbr_fd(g->moves, 1);
	write(1, "\n", 1);
}

void	try_move(t_game *g, int dx, int dy)
{
	int		x;
	int		y;
	char	target;

	x = g->map.player_x + dx;
	y = g->map.player_y + dy;
	if (!can_move(g, x, y))
		return ;
	target = g->map.grid[y][x];
	if (target == 'C')
		g->collected++;
	update_player_position(g, x, y, target);
	g->moves++;
	print_moves(g);
	if (target == 'E' && g->collected == g->map.collectibles)
	{
		write(1, "You win!\n", 9);
		exit_game(g);
	}
}
