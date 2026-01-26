/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:32:52 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:44:24 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>

void	init_image(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		return ;
	f->buf = mlx_get_data_addr(f->img, &f->bpp, &f->line, &f->endian);
}

void	init_fractol(t_fractol *f, int ac, char **av)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	f->max_iter = MAX_ITER;
	f->j_cr = -0.7;
	f->j_ci = 0.27015;
	f->set = MANDELBROT;
	f->min_r = -2.0;
	f->max_r = 1.0;
	f->min_i = -1.2;
	f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	if (ac >= 2)
	{
		if (av[1][0] == 'J' || av[1][0] == 'j')
			f->set = JULIA;
		else if (av[1][0] == 'T' || av[1][0] == 't')
			f->set = TRICORN;
		if (f->set == JULIA && ac >= 4)
		{
			f->j_cr = ft_atof(av[2]);
			f->j_ci = ft_atof(av[3]);
		}
	}
	init_image(f);
	build_palette(f);
}
