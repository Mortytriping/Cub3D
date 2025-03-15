/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:33:32 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/18 14:33:41 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*after;
	t_list	*stock;

	after = *lst;
	while (after != 0)
	{
		stock = after->next;
		del(after->content);
		free(after);
		after = stock;
	}
	*lst = after;
}
