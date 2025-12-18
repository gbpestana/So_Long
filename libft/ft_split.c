/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:26:57 by grodrig2          #+#    #+#             */
/*   Updated: 2025/08/06 13:44:43 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_fill_arr(char **arr, const char *str, char c, unsigned int n);
static int	ft_word(const char *str, char c);
static size_t	ft_counter_char(const char *str, char c);
static void	ft_free(char **arr, unsigned int n);

static char	**ft_fill_arr(char **arr, const char *str, char c, unsigned int n)
{
	char				*str_cpy;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (*str == c)
			str++;
		str_cpy = malloc (ft_word(str, c) + 1);
		if (!str_cpy)
		{
			ft_free (arr, i);
			return (NULL);
		}
		while (*str && *str != c)
			str_cpy[j++] = *str++;
		str_cpy[j] = '\0';
		arr[i] = str_cpy;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

static int	ft_word(const char *str, char c)
{
	int	counter;

	counter = 0;
	while (*str && *str != c)
	{
		counter++;
		str++;
	}
	return (counter);
}

static size_t	ft_counter_char(const char *str, char c)
{
	char	*str2;
	size_t	counter;
	size_t	word;

	word = 0;
	counter = 0;
	str2 = (char *)str;
	while (*str2)
	{
		if (*str2 != c)
			word = 1;
		if (word && *str2 == c)
		{
			counter++;
			word = 0;
		}
		str2++;
	}
	return (counter + word);
}

static void	ft_free(char **arr, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**new_arr;
	unsigned int	n_words;

	if (!s)
		return (NULL);
	n_words = ft_counter_char(s, c);
	new_arr = (char **)ft_calloc(n_words + 1, sizeof (char *));
	if (!new_arr)
		return (NULL);
	if (!ft_fill_arr(new_arr, s, c, n_words))
		return (NULL);
	return (new_arr);
}
