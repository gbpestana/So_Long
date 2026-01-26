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

int	handle_keypress(int keycode, t_game *g)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		g->input.up = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		g->input.down = 1;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		g->input.left = 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		g->input.right = 1;
	else if (keycode == KEY_ESC)
		exit_game(g);
	return (0);
}

int	handle_keyrelease(int keycode, t_game *g)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		g->input.up = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		g->input.down = 0;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		g->input.left = 0;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		g->input.right = 0;
	return (0);
}
