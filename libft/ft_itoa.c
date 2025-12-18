/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:17:41 by grodrig2          #+#    #+#             */
/*   Updated: 2025/08/06 13:31:59 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		len ++;
	}
	return (len);
}

static char	*ft_char_atoi(unsigned int nbr, int len, int sig)
{
	char	*str;

	str = malloc (len + sig + 1);
	if (str == NULL)
		return (NULL);
	str[len + sig] = '\0';
	while (len > 0)
	{
		str[--len + sig] = '0' + (nbr % 10);
		nbr /= 10;
	}
	if (sig)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				signal;
	int				count;

	if (n < 0)
	{
		signal = 1;
		nbr = (unsigned int) -(long)n;
	}
	else
	{
		signal = 0;
		nbr = (unsigned int) n;
	}
	count = ft_len(nbr);
	return (ft_char_atoi(nbr, count, signal));
}
