/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:44:08 by grodrig2          #+#    #+#             */
/*   Updated: 2025/07/25 10:33:03 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}
