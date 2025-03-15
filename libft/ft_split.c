/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:45:51 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/15 18:45:59 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	stc_strlen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != c))
		i++;
	return (i);
}

static int	stc_countwords(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while ((s[i] == c) && s[i])
			i++;
		if ((s[i] != c) && s[i])
			words++;
		while ((s[i] != c) && s[i])
			i++;
	}
	return (words);
}

static char	**freearray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

static char	*stc_strdup(const char *src, char c)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (stc_strlen(src, c) + 1));
	if (dup == 0)
		return (dup);
	while (src[i] && (src[i] != c))
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		x;

	split = malloc(sizeof(char *) * (stc_countwords(s, c) + 1));
	if (split == 0)
		return (split);
	i = 0;
	x = 0;
	while (s[i])
	{
		while ((s[i] == c) && s[i])
			i++;
		if ((s[i] != c) && s[i])
		{
			split[x] = stc_strdup(&s[i], c);
			if (split[x++] == 0)
				return (freearray(split));
		}
		while ((s[i] != c) && s[i])
		i++;
	}
	split[x] = 0;
	return (split);
}

/* int main()
{
	ft_split("hello!", ' ');
} */