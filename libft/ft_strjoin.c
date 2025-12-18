/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:34:01 by grodrig2          #+#    #+#             */
/*   Updated: 2025/08/02 13:18:31 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*join;

	if (!s1)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = ft_calloc (len, sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, len);
	ft_strlcat(join, s2, len);
	return (join);
}
