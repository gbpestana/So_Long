/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:43:26 by grodrig2          #+#    #+#             */
/*   Updated: 2025/08/02 13:25:28 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	ptr_src = (unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	if (ptr_src == ptr_dest || n == 0)
		return (dest);
	if (ptr_dest < ptr_src)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		n--;
		ptr_dest[n] = ptr_src[n];
	}
	return (dest);
}
