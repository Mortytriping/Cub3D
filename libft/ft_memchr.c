/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:17:29 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/13 11:17:30 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	unsigned char	*null;
	size_t			i;

	null = 0;
	if (n <= 0)
		return (null);
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while ((i < n))
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	return (null);
}
