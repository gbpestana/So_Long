/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:51:46 by grodrig2          #+#    #+#             */
/*   Updated: 2025/08/02 12:36:19 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	size;

	size = 0;
	if (n > 0)
	{
		while (size < n && (*s1 || *s2))
		{
			if (*s1 != *s2)
				return ((unsigned char)*s1 - (unsigned char)*s2);
			s1++;
			s2++;
			size++;
		}
	}
	return (0);
}
