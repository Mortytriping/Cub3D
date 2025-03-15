/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:39:44 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/13 14:39:46 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	cpy = malloc(sizeof(const char) * (i + 1));
	if (cpy == 0)
		return (cpy);
	i = 0;
	while (s[i])
	{
		cpy[i] = ((char *)s)[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
