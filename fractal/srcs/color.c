/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:33:08 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:44:11 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>

static int	get_r(int c)
{
	return ((c >> 16) & 0xFF);
}

static int	get_g(int c)
{
	return ((c >> 8) & 0xFF);
}

static int	get_b(int c)
{
	return (c & 0xFF);
}

static int	interpolate(int c1, int c2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1.0 - t) * get_r(c1) + t * get_r(c2));
	g = (int)((1.0 - t) * get_g(c1) + t * get_g(c2));
	b = (int)((1.0 - t) * get_b(c1) + t * get_b(c2));
	return ((r << 16) | (g << 8) | b);
}

void	build_palette(t_fractol *f)
{
	int		i;
	int		wave;
	double	t;
	int		c[3];

	c[0] = 0xFF00FF;
	c[1] = 0x00FFFF;
	c[2] = 0xFFFF00;
	f->palette = malloc(sizeof(int) * (f->max_iter + 1));
	if (!f->palette)
		return ;
	i = 0;
	while (i < f->max_iter)
	{
		wave = (i / 10) % 3;
		t = (double)(i % 10) / 10.0;
		f->palette[i] = interpolate(
				c[wave],
				c[(wave + 1) % 3],
				t);
		i++;
	}
	f->palette[f->max_iter] = 0x000000;
}
