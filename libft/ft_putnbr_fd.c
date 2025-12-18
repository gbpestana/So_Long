/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:18:36 by grodrig2          #+#    #+#             */
/*   Updated: 2025/07/25 10:19:04 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int) -n;
	}
	else
		nbr = (unsigned int)n;
	if (nbr > 9)
		ft_putnbr_fd((nbr / 10), fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}
