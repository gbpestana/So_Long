/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:27:07 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/26 11:03:48 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *g)
{
	g->moves = 0;
	g->collected = 0;
	g->speed = 10;
	g->frame_count = 0;
	g->input.up = 0;
	g->input.down = 0;
	g->input.left = 0;
	g->input.right = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		print_error("Usage: ./so_long <map.ber>");
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	if (!parse_map(argv[1], &game))
	{
		print_error("Map validation failed!");
		return (1);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * TILE_SIZE, game.map.height * TILE_SIZE, "so_long");
	load_textures(&game);
	render_map(&game);
	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 3, 1L << 1, handle_keyrelease, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);

	return (0);
}
