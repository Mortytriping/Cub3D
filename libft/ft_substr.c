/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:59 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/13 14:58:01 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ftlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	getsize(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (start > ftlen(s))
		return (i);
	while (s[i + start] && (i < len))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	unsigned long	size;

	size = getsize(s, start, len);
	sub = malloc(sizeof(char) * (size + 1));
	if (sub == 0)
		return (sub);
	i = 0;
	if (!(start > (unsigned int)ftlen(s)))
	{
		while (s[i + start] && (i < len))
		{
			sub[i] = s[i + start];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
