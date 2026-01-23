/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:26:38 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/23 15:26:39 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	free_map(&g->map);
	exit(0);
}

int	handle_keypress(int keycode, t_game *g)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		try_move(g, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		try_move(g, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		try_move(g, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		try_move(g, 1, 0);
	else if (keycode == KEY_ESC)
		exit_game(g);
	render_map(g);
	return (0);
}

int	handle_close(t_game *g)
{
	exit_game(g);
	return (0);
}
