#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

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
int		ft_strlen(char *str);
char	*ft_strdup(char *str);

#endif
