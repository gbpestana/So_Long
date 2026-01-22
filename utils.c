#include "so_long.h"

// int		ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(char *s)
// {
// 	int		i;
// 	int		len;
// 	char	*ptr;

// 	len = ft_strlen(s) + 1;
// 	ptr = malloc(len * sizeof(char));
// 	if (ptr == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		ptr[i] = s[i];
// 		i++;
// 	}
// 	return (ptr);
// }

void	print_error(char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		write(2, &message[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return;
	i = 0;
	while (i < map->height && map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

// static int	ft_len(unsigned int nbr)
// {
// 	int	len;

// 	len = 1;
// 	while (nbr > 9)
// 	{
// 		nbr /= 10;
// 		len ++;
// 	}
// 	return (len);
// }

// static char	*ft_char_atoi(unsigned int nbr, int len, int sig)
// {
// 	char	*str;

// 	str = malloc (len + sig + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	str[len + sig] = '\0';
// 	while (len > 0)
// 	{
// 		str[--len + sig] = '0' + (nbr % 10);
// 		nbr /= 10;
// 	}
// 	if (sig)
// 		str[0] = '-';
// 	return (str);
// }

// char	*ft_itoa(int n)
// {
// 	unsigned int	nbr;
// 	int				signal;
// 	int				count;

// 	if (n < 0)
// 	{
// 		signal = 1;
// 		nbr = (unsigned int) -(long)n;
// 	}
// 	else
// 	{
// 		signal = 0;
// 		nbr = (unsigned int) n;
// 	}
// 	count = ft_len(nbr);
// 	return (ft_char_atoi(nbr, count, signal));
// }
