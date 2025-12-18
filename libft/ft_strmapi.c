/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:26:30 by grodrig2          #+#    #+#             */
/*   Updated: 2025/07/29 09:26:33 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str_result;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str_result = malloc(sizeof(char) * (len + 1));
	if (!str_result)
		return (NULL);
	while (i < len)
	{
		str_result[i] = f(i, s[i]);
		i++;
	}
	str_result[i] = '\0';
	return (str_result);
}
