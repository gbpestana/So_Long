/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:26:33 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/23 15:40:34 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(t_game *game)
{
	char	c;

	printf("Move (w/a/s/d, q to quit): ");
	if (scanf(" %c", &c) != 1)
		return (0);
	if (c == 'w')
		try_move(game, 0, -1);
	else if (c == 's')
		try_move(game, 0, 1);
	else if (c == 'a')
		try_move(game, -1, 0);
	else if (c == 'd')
		try_move(game, 1, 0);
	else if (c == 'q')
		return (0);
	return (1);
}
