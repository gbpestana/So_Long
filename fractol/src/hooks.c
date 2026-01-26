/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:18:04 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/09/19 19:16:41 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 65307)
		ft_clean_exit(f);
	return (0);
}

int	close_window(t_fractol *f)
{
	ft_clean_exit(f);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	double	mx_old;
	double	my_old;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	mx_old = ft_map_x_to_real(x, f);
	my_old = ft_map_y_to_imag(y, f);
	if (button == 4)
		f->zoom *= 1.1;
	else if (button == 5)
		f->zoom /= 1.1;
	else
		return (0);
	f->offset_x += mx_old - ft_map_x_to_real(x, f);
	f->offset_y += my_old - ft_map_y_to_imag(y, f);
	if (f->fractal_type == MANDELBROT)
		render_mandelbrot(f);
	else
		render_julia(f);
	return (0);
}
