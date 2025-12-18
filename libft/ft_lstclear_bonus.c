/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grodrig2 <grodrig2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:46:34 by grodrig2          #+#    #+#             */
/*   Updated: 2025/08/02 12:38:31 by grodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_nd;

	while ((*lst))
	{
		next_nd = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next_nd;
	}
	*lst = NULL;
}
