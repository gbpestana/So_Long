/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:50:23 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/19 19:21:32 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	julia_iterations(t_complex z, t_fractol *f);

static int	julia_iterations(t_complex z, t_fractol *f)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < f->max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + f->julia_cx;
		z.im = 2.0 * z.re * z.im + f->julia_cy;
		z.re = tmp;
		iter++;
	}
	return (iter);
}

void	render_julia(t_fractol *f)
{
	int			x;
	int			y;
	int			iter;
	t_complex	z;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.re = ft_map_x_to_real(x, f);
			z.im = ft_map_y_to_imag(y, f);
			iter = julia_iterations(z, f);
			put_pixel(f, x, y, color_from_iter(iter, f->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
