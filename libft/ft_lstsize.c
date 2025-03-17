/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:03:18 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/15 11:57:35 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count_items;
	t_list	*current;

	current = lst;
	count_items = 0;
	while (current)
	{
		current = current->next;
		count_items++;
	}
	return (count_items);
}
