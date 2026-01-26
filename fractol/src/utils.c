/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:50:37 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/19 19:22:18 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	get_decimal_part(const char *str);

static double	get_decimal_part(const char *str)
{
	double	dec;
	double	res;

	dec = 0.1;
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res += (*str - '0') * dec;
		dec *= 0.1;
		str++;
	}
	return (res);
}

double	ft_atof(const char *str)
{
	double	res;
	int		neg;

	res = 0;
	neg = 0;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		res += get_decimal_part(str);
	}
	if (neg)
		res = -res;
	return (res);
}

void	error_and_exit(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(2, &msg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

int	ft_clean_exit(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' && i < n) || (s2[i] != '\0' && i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
