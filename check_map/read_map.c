#include "so_long.h"
static int	count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	c;
	int		last_nl;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	last_nl = 1;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			lines++;
			last_nl = 1;
		}
		else
			last_nl = 0;
	}
	close(fd);
	if (!last_nl)
		lines++;
	return (lines);
}

static int	has_ber_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (filename[len - 4] != '.' ||
		filename[len - 3] != 'b' ||
		filename[len - 2] != 'e' ||
		filename[len - 1] != 'r')
		return (0);
	return (1);
}

static char	*read_line(int fd)
{
	char	buffer[10000];
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			break;
		if (i < 9999)
			buffer[i++] = c;
	}
	if (i == 0)
		return (NULL);
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}

static int	open_map(char *filename, t_map *map)
{
	if (!has_ber_extension(filename))
		return (-1);
	map->height = count_lines(filename);
	if (map->height <= 0)
		return (-1);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (-1);
	return (open(filename, O_RDONLY));
}

int	read_map(char *filename, t_map *map)
{
	int	fd;
	int	i;

	fd = open_map(filename, map);
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
