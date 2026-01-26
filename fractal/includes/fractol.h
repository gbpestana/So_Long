/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:33:14 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:45:28 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 1000

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP     65362
# define KEY_DOWN   65364
# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_PLUS   61
# define KEY_MINUS  45

# define MOUSE_SCROLL_UP   4
# define MOUSE_SCROLL_DOWN 5

typedef enum e_set
{
	MANDELBROT,
	JULIA,
	TRICORN
}	t_set;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		bpp;
	int		line;
	int		endian;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	j_cr;
	double	j_ci;
	double	pixel_w;
	double	pixel_h;
	int		max_iter;
	int		*palette;
	int		set;
}	t_fractol;

/* main */
int		main(int ac, char **av);

/* help */
void	print_help(void);

/* init */
void	init_fractol(t_fractol *f, int ac, char **av);
void	init_image(t_fractol *f);

/* render */
void	render(t_fractol *f);

/* fractals */
int		mandelbrot(double cr, double ci, int max_iter);
int		julia(t_fractol *f, double zr, double zi, int max_iter);
int		tricorn(double cr, double ci, int max_iter);

/* color */
void	build_palette(t_fractol *f);
int		interpolate_color(int c1, int c2, double t);

/* hooks */
int		key_hook(int keycode, t_fractol *f);
int		mouse_hook(int button, int x, int y, t_fractol *f);

/* utils */
double	ft_atof(const char *s);
void	put_pixel(t_fractol *f, int x, int y, int color);
int		close_window(t_fractol *f);

#endif