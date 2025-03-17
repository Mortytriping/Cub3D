/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:59:44 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/29 16:34:16 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	j = 0;
	src_len = 0;
	while (dest[i])
		i++;
	dest_len = i;
	while (src[src_len])
		src_len++;
	if (count <= dest_len)
		return (count + src_len);
	while (src[j] && i < count - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < count)
		dest[i] = '\0';
	return (src_len + dest_len);
}
