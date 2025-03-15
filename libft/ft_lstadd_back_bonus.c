/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:50:01 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/17 14:21:25 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == 0)
		return ;
	if (*lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
		return ;
	}
	temp = *lst;
	*lst = new;
	new->next = temp;
}
