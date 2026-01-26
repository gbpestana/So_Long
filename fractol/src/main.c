/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:20:25 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/19 19:21:47 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	render_fractal(t_fractol *f);
static void	ft_hooks(t_fractol *f);

static void	ft_hooks(t_fractol *f)
{
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 17, 0, close_window, f);
}

void	init_fract(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		ft_clean_exit(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!f->win)
		ft_clean_exit(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		ft_clean_exit(f);
	f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->size_line, &f->end);
	if (!f->img_data)
		ft_clean_exit(f);
}

static void	render_fractal(t_fractol *f)
{
	if (f->fractal_type == MANDELBROT)
		render_mandelbrot(f);
	else
		render_julia(f);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	f.max_iter = MAX_ITER;
	f.zoom = 1;
	f.offset_x = 0;
	f.offset_y = 0;
	if (argc < 2)
		error_and_exit("Usage: ./fractol mandelbrot | julia <real> <imag>");
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		f.fractal_type = MANDELBROT;
	else if (!ft_strncmp(argv[1], "julia", 5) && argc == 4)
	{
		f.fractal_type = JULIA;
		f.julia_cx = ft_atof(argv[2]);
		f.julia_cy = ft_atof(argv[3]);
	}
	else
		error_and_exit("Invalid fractal or missing Julia parameters");
	init_fract(&f);
	ft_hooks(&f);
	render_fractal(&f);
	mlx_loop(f.mlx);
	return (0);
}
