/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:26:01 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/12 15:26:03 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dest == 0 && src == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* int main()
{

	char	test1[10] = "abcde";
	char	test1dest[50] = "";
	char	*t = test1;

	printf("\n------------------------------\n");
	printf("\n<%s>\n", (char *)memcpy(&test1[2], test1, 3));
	printf("\n<%s>\n", t);


} */
