/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:44:25 by grodrig2          #+#    #+#             */
/*   Updated: 2025/07/25 12:12:21 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	aux_size;
	size_t	len_src;
	size_t	len_dst;

	if (size == 0)
		return (ft_strlen(src));
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (len_dst >= size)
		return (len_src + size);
	aux_size = size - 1 - len_dst;
	dst += len_dst;
	while ((aux_size-- > 0) && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (len_src + len_dst);
}
