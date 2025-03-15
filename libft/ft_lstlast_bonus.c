/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:57:54 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/17 10:57:55 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;
	int		i;

	last = lst;
	i = 0;
	if (lst == 0)
		return (lst);
	while (last->next)
	{
		last = last->next;
		i--;
	}
	return (last);
}
