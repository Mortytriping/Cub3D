/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:43:58 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/29 16:34:40 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		if (to_find[0] == str[i])
		{
			j = 0;
			while (str[i + j] && to_find[j] && (i + j) < len
				&& str[i + j] == to_find[j])
			{
				j++;
			}
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
