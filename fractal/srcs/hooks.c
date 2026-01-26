/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:33:00 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:44:15 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>

static void	zoom_at(t_fractol *f, double zoom, int mx, int my)
{
	double	cr;
	double	ci;
	double	w;
	double	h;

	cr = f->min_r + (double)mx * (f->max_r - f->min_r) / (double)WIDTH;
	ci = f->max_i + (double)my * (f->min_i - f->max_i) / (double)HEIGHT;
	w = f->max_r - f->min_r;
	h = f->max_i - f->min_i;
	w *= zoom;
	h *= zoom;
	f->min_r = cr - w * (double)mx / (double)WIDTH;
	f->max_r = f->min_r + w;
	f->max_i = ci + h * (double)my / (double)HEIGHT;
	f->min_i = f->max_i - h;
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == MOUSE_SCROLL_UP)
	{
		zoom_at(f, 0.5, x, y);
		render(f);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		zoom_at(f, 2.0, x, y);
		render(f);
	}
	return (0);
}

static void	move_fractol(t_fractol *f, int key)
{
	double	dx;
	double	dy;

	dx = (f->max_r - f->min_r) * 0.1;
	dy = (f->max_i - f->min_i) * 0.1;
	if (key == KEY_W || key == KEY_UP)
	{
		f->min_i += dy;
		f->max_i += dy;
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		f->min_i -= dy;
		f->max_i -= dy;
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		f->min_r -= dx;
		f->max_r -= dx;
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		f->min_r += dx;
		f->max_r += dx;
	}
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		close_window(f);
	else
		move_fractol(f, keycode);
	render(f);
	return (0);
}
