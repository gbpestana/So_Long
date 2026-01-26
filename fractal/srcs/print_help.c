/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:32:43 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:44:32 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_putendl_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	print_help(void)
{
	ft_putendl_fd("====================================", 1);
	ft_putendl_fd("        FRACT-OL — HELP MENU        ", 1);
	ft_putendl_fd("====================================", 1);
	ft_putendl_fd("Uso:", 1);
	ft_putendl_fd("  ./fractol mandelbrot/m/M", 1);
	ft_putendl_fd("  ./fractol julia/j/J <real> <imag>", 1);
	ft_putendl_fd("  ./fractol tricorn/t/T", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Exemplos:", 1);
	ft_putendl_fd("  ./fractol mandelbrot", 1);
	ft_putendl_fd("  ./fractol julia -0.8 0.156", 1);
	ft_putendl_fd("  ./fractol tricorn", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Controles:", 1);
	ft_putendl_fd("  Scroll            → Zoom", 1);
	ft_putendl_fd("  WASD / Setas      → Mover", 1);
	ft_putendl_fd("  ESC               → Sair", 1);
	ft_putendl_fd("====================================", 1);
}
