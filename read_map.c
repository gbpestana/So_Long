#include "so_long.h"

static int count_lines(char *filename)
{
    int		fd;
    int		lines;
    char	buffer[1];
    int		bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while ((bytes = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}

static char *read_line(int fd)
{
	char	buffer[10000];
	char 	c;
	int		i;
	int		bytes;

	i = 0;
	while ((bytes = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			break;
		buffer[i++] = c;
	}
	if (bytes <= 0 && i == 0)
		return (NULL);
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}

int	read_map(char *filename, t_map *map)
{
	int	fd;
	int	i;

	if (ft_strlen(filename) < 4)
		return (0);
	if (filename[ft_strlen(filename) - 4] != '.' || 
		filename[ft_strlen(filename) - 3] != 'b' ||
		filename[ft_strlen(filename) - 2] != 'e' ||
		filename[ft_strlen(filename) - 1] != 'r')
		return (0);
	map->height = count_lines(filename);
	if (map->height <= 0)
		return (0);
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = read_line(fd);
		if (!map->grid[i])
			return (0);
		if (i == 0)
			map->width = ft_strlen(map->grid[i]);
		i++;
	}
	map->grid[i] = NULL;
	close(fd);
	return (1);
}
