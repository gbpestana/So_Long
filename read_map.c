#include "so_long.h"

static int count_lines(char *filename)
{
    int		fd;
    int		lines;
    char	buffer[1];
    int		bytes;

	fd = open(filename, O_RDONLY):
	if (fd < 0)
		return (-1);
	lines = 0;
	while ((bytes = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			lines++;
	}
}