/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:19:03 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/09/19 19:21:11 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	ft_create_trgb(int t, int r, int g, int b);

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img_data + (y * f->size_line + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

double	ft_map_x_to_real(int x, t_fractol *f)
{
	double	mapx;

	mapx = f->offset_x + (x / (double)WIDTH) * (4.0 / f->zoom) - 2.0 / f->zoom;
	return (mapx);
}

double	ft_map_y_to_imag(int y, t_fractol *f)
{
	double	mapy;

	mapy = f->offset_y + (y / (double)HEIGHT) * (4.0 / f->zoom) - 2.0 / f->zoom;
	return (mapy);
}

static int	ft_create_trgb(int t, int r, int g, int b)
{
	int	color;

	color = (t << 24 | r << 16 | g << 8 | b);
	return (color);
}

int	color_from_iter(int iter, int max_iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == max_iter)
		return (0x000000);
	r = (iter * 10) % 256;
	g = (iter * 25) % 256;
	b = (iter * 45) % 256;
	return (ft_create_trgb(0, r, g, b));
}
