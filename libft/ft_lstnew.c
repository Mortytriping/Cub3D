/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:11:59 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/27 17:11:43 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_item;

	new_item = malloc(sizeof(*new_item) * 1);
	if (!new_item)
		return (NULL);
	new_item->content = content;
	new_item->next = NULL;
	return (new_item);
}
