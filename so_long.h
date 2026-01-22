#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define KEY_ESC   65307
# define KEY_W     119
# define KEY_A     97
# define KEY_S     115
# define KEY_D     100

# define TILE_SIZE 64

# define COLOR_WALL  0x444444
# define COLOR_FLOOR 0xDDDDDD
# define COLOR_PLAYER 0x0000FF
# define COLOR_EXIT  0x00FF00
# define COLOR_COLLECT 0xFFD700

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

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*win;
	int		collected;
	int		moves;
}	t_game;

int	parse_map(char *filename, t_game *game);
int	read_map(char *filename, t_map *map);
int	validate_map(t_map *map);
int	check_rectangular(t_map *map);
int	check_walls(t_map *map);
int	check_components(t_map *map);
int	check_path(t_map *map);

void	free_map(t_map *map);
void	print_error(char *message);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);

void	init_game(t_game *game);
int		handle_input(t_game *game);
void	try_move(t_game *g, int dx, int dy);
int	handle_keypress(int keycode, t_game *game);
int	handle_close(t_game *game);

void	draw_square(t_game *game, int x, int y, int color);
void	render_map(t_game *game);
void	render_moves(t_game *g);

#endif
