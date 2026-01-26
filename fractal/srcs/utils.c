/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:32:27 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:44:43 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stddef.h>

int	has_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	skip_sign_ws(const char **s, int *neg)
{
	while (**s == ' ' || **s == '\t' || **s == '\n'
		|| **s == '\r' || **s == '\v' || **s == '\f')
		(*s)++;
	if (**s == '-')
	{
		*neg = -1;
		(*s)++;
	}
	else if (**s == '+')
		(*s)++;
	return (0);
}

static double	ft_parse_decimal(const char *s, double *val)
{
	double	div;

	div = 1.0;
	while (*s && has_digit(*s))
	{
		*val = *val * 10.0 + (*s - '0');
		div *= 10.0;
		s++;
	}
	return (div);
}

double	ft_atof(const char *s)
{
	double	sign;
	double	val;
	double	div;
	int		neg;

	sign = 1.0;
	val = 0.0;
	div = 1.0;
	neg = 1;
	skip_sign_ws(&s, &neg);
	if (neg == -1)
		sign = -1.0;
	while (*s && has_digit(*s))
	{
		val = val * 10.0 + (*s - '0');
		s++;
	}
	if (*s == '.')
	{
		s++;
		div = ft_parse_decimal(s, &val);
	}
	return (sign * (val / div));
}

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	int	idx;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	idx = (y * f->line) + (x * (f->bpp / 8));
	f->buf[idx + 0] = (color) & 0xFF;
	f->buf[idx + 1] = (color >> 8) & 0xFF;
	f->buf[idx + 2] = (color >> 16) & 0xFF;
	f->buf[idx + 3] = (color >> 24) & 0xFF;
}
