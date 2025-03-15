/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:39:45 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/12 21:39:46 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	lensrc;
	size_t	lendest;
	size_t	i;

	lendest = 0;
	while (dst[lendest])
		lendest++;
	lensrc = 0;
	while (src[lensrc])
		lensrc++;
	i = 0;
	if (siz > 0)
	{
		while (((lendest + i) < (siz - 1)) && src[i])
		{
			dst[lendest + i] = src[i];
			i++;
		}
		if (siz > (lendest + i))
			dst[lendest + i] = '\0';
	}
	if (siz > lendest)
		return (lensrc + lendest);
	return (lensrc + siz);
}

/* int main()
{
	char dest[100] = "pqrstuvwxyz";
	const char src[8] = "abcd";

	printf("\n dest = <%s>", &dest[0]);
	printf("\n src = <%s>", &src[0]);
	printf("\nreturn value = %zu", ft_strlcat(&dest[0], &src[0], 0));
	printf("\n dest = <%s>", &dest[0]);
	printf("\n src = <%s>", &src[0]);
} */
