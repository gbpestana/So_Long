/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:33:04 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:44:05 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < max_iter)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		tmp = 2.0 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		++i;
	}
	return (i);
}

int	julia(t_fractol *f, double zr, double zi, int max_iter)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < max_iter)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		tmp = 2.0 * zr * zi + f->j_ci;
		zr = zr * zr - zi * zi + f->j_cr;
		zi = tmp;
		++i;
	}
	return (i);
}

int	tricorn(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < max_iter)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		tmp = zr * zr - zi * zi + cr;
		zi = -2.0 * zr * zi + ci;
		zr = tmp;
		++i;
	}
	return (i);
}
