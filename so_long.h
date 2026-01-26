/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:27:12 by grodrig2          #+#    #+#             */
/*   Updated: 2026/01/26 13:40:33 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include "libft.h"

# define KEY_ESC   65307
# define KEY_W     119
# define KEY_A     97
# define KEY_S     115
# define KEY_D     100
# define KEY_UP     65362
# define KEY_LEFT   65361
# define KEY_DOWN   65364
# define KEY_RIGHT  65363

# define TILE_SIZE 32

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		players;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_tex
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_tex;

typedef struct s_input
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_input;

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*win;
	t_tex	tex;
	t_input	input;
	int		collected;
	int		moves;
	int		speed;
	int		frame_count;
}	t_game;

int		parse_map(char *filename, t_game *game);
int		read_map(char *filename, t_map *map);
int		validate_map(t_map *map);
int		check_rectangular(t_map *map);
int		check_walls(t_map *map);
int		check_components(t_map *map);
int		check_path(t_map *map);
void	load_textures(t_game *g);

void	free_map(t_map *map);
void	print_error(char *message);
void	exit_game(t_game *g);

void	init_game(t_game *game);
void	try_move(t_game *g, int dx, int dy);
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *g);
int		handle_close(t_game *game);
int		game_loop(t_game *g);

void	destroy_textures(t_game *g);
void	render_map(t_game *game);
void	render_moves(t_game *g);

#endif
