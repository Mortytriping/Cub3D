/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:11:54 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/12 16:11:56 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	const char		*s;
	unsigned char	*d;

	s = (const char *)src;
	d = (unsigned char *)dest;
	if ((d == 0 && s == 0) || n <= 0)
		return (dest);
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i--)
	{
		d[i] = s[i];
	}
	return (dest);
}
