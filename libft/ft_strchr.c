/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:53:38 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/12 22:53:39 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = (char *)s;
	i = 0;
	while (s[i])
	{
		if (res[i] == (char)c)
			return (&res[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&res[i]);
	return (0);
}
