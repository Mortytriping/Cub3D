/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:57:13 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/15 16:34:18 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_liste;
	t_list	*content;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_liste = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		content = ft_lstnew(new_content);
		if (!content)
		{
			del(new_content);
			ft_lstclear(&new_liste, del);
			return (NULL);
		}
		ft_lstadd_back(&new_liste, content);
		lst = lst->next;
	}
	return (new_liste);
}
