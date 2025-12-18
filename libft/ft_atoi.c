/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:38:43 by grodrig2          #+#    #+#             */
/*   Updated: 2025/07/23 14:50:54 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	signal;

	nbr = 0;
	signal = 1;
	while (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == 32))
		nptr++;
	if (*nptr == '-')
	{
		signal *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit((int)*nptr))
	{
		nbr = (nbr * 10) + ((int)*nptr - '0');
		nptr++;
	}
	return (nbr * signal);
}
