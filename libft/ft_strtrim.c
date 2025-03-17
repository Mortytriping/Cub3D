/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:09:37 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/29 16:34:50 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		i;
	int		start;
	int		end;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && (is_set(s1[i], set)))
		i++;
	start = i;
	i = ft_strlen(s1);
	while (i > 0 && (is_set(s1[i - 1], set)))
		i--;
	end = i;
	if (start >= end)
		return (ft_strdup(""));
	new_str = malloc(sizeof(char) * (end - start + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (start < end)
		new_str[i++] = s1[start++];
	new_str[i] = '\0';
	return (new_str);
}
