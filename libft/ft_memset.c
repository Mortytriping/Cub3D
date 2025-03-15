/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:42:36 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/10 16:42:41 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temps;
	size_t			i;

	temps = s;
	i = 0;
	while (i < n)
	{
		*(temps + i) = (const unsigned char)c;
		i++;
	}
	return (s);
}
