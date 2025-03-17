/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:43:50 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/29 16:33:36 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_strs(char **strs, int num_words)
{
	int	i;

	i = 0;
	while (i < num_words)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	*malloc_word(const char *str, char c, char **strs, int words_alloc)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		free_strs(strs, words_alloc);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
		{
			strs[i] = malloc_word(&s[j], c, strs, i);
			if (!strs[i])
				return (NULL);
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	strs[i] = NULL;
	return (strs);
}
