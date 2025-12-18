/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:19:18 by grodrig2          #+#    #+#             */
/*   Updated: 2025/07/25 15:19:53 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	sub_str = malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	s += start;
	ft_memcpy(sub_str, s, len);
	sub_str[len] = '\0';
	return (sub_str);
}
