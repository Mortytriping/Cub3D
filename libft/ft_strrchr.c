/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:07:58 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/12 23:08:02 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = (char *)s;
	i = 0;
	while (s[i])
	{
		i++;
	}
	if ((char)c == '\0')
		return (&res[i]);
	while (i > -1)
	{
		if (res[i] == (char)c)
			return (&res[i]);
		i--;
	}
	return (0);
}
