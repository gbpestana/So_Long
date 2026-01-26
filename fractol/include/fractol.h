/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:25:30 by thiagouemur       #+#    #+#             */
/*   Updated: 2026/01/26 13:37:52 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 150
# define MANDELBROT 1
# define JULIA 2

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			end;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iter;
	int			fractal_type;
	double		julia_cx;
	double		julia_cy;
	t_complex	c;
}				t_fractol;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		init_fract(t_fractol *f);
void		render_mandelbrot(t_fractol *f);
void		render_julia(t_fractol *f);
int			close_window(t_fractol *f);
int			key_hook(int keycode, t_fractol *f);
double		ft_atof(const char *str);
int			ft_clean_exit(t_fractol *f);
void		put_pixel(t_fractol *f, int x, int y, int color);
double		ft_map_x_to_real(int x, t_fractol *f);
double		ft_map_y_to_imag(int y, t_fractol *f);
int			color_from_iter(int iter, int max_iter);
void		error_and_exit(char *msg);
int			mouse_hook(int button, int x, int y, t_fractol *f);

#endif
