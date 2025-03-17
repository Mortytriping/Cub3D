/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:03:34 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/29 16:32:56 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	a = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (a == ptr[i])
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
