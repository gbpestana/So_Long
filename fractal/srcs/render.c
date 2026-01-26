/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:32:38 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:44:39 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	compute_pixel(t_fractol *f, int x, int y)
{
	double	pr;
	double	pi;
	int		iter;

	pr = f->min_r + x * f->pixel_w;
	pi = f->max_i - y * f->pixel_h;
	if (f->set == MANDELBROT)
		iter = mandelbrot(pr, pi, f->max_iter);
	else if (f->set == JULIA)
		iter = julia(f, pr, pi, f->max_iter);
	else
		iter = tricorn(pr, pi, f->max_iter);
	put_pixel(f, x, y, f->palette[iter]);
}

void	render(t_fractol *f)
{
	int	x;
	int	y;

	f->pixel_w = (f->max_r - f->min_r) / WIDTH;
	f->pixel_h = (f->max_i - f->min_i) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			compute_pixel(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
