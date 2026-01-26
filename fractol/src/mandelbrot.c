/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:50:34 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/19 19:22:01 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	mandelbrot_iterations(t_complex c, t_fractol *f);

static int	mandelbrot_iterations(t_complex c, t_fractol *f)
{
	t_complex	z;
	double		tmp;
	int			iter;

	z.re = 0;
	z.im = 0;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < f->max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		iter++;
	}
	return (iter);
}

void	render_mandelbrot(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	c;
	int			iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = ft_map_x_to_real(x, f);
			c.im = ft_map_y_to_imag(y, f);
			iter = mandelbrot_iterations(c, f);
			put_pixel(f, x, y, color_from_iter(iter, f->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
