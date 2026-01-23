/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:27:01 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/23 15:44:03 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_moves(t_game *g)
{
	char	*str;
	char	*num;

	num = ft_itoa(g->moves);
	str = ft_strjoin("Moves: ", num);
	mlx_string_put(g->mlx, g->win, 10, 20, 0xFFFFFF, str);
	free(num);
	free(str);
}
