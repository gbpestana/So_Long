/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:45:01 by grodrig2          #+#    #+#             */
/*   Updated: 2025/07/23 14:47:49 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*ptr_big;
	size_t		little_len;

	ptr_big = big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*ptr_big && len > 0)
	{
		if (*ptr_big == *little)
		{
			if (little_len <= len)
			{
				if (ft_strncmp(ptr_big, little, little_len) == 0)
					return ((char *)ptr_big);
			}
		}
		ptr_big++;
		len--;
	}
	return (NULL);
}
