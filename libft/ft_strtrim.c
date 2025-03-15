/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:45:22 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/15 18:45:34 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t	ft_strlen(const char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
} */

static int	isset(char s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1 == s2[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_strncpy_until(char *dst, const char *src, int i, int l)
{
	int	j;

	j = 0;
	if (i < 0)
	{
		dst[j] = '\0';
		return ;
	}
	while (src[j] && l != (i + 1))
	{
		dst[j] = src[j];
		l++;
		j++;
	}
	dst[j] = '\0';
}

static size_t	getsize(char const *s1, char const *set)
{
	int				i;
	int				l;
	unsigned int	res;

	res = ft_strlen(s1);
	i = ft_strlen(s1) - 1;
	while (isset(s1[i], set) && i--)
			res--;
	l = 0;
	if (i == -1 && isset(s1[i + 1], set))
		res--;
	if (i >= 0 && s1[i])
	{
		while (s1[l] && isset(s1[l], set))
		{
			l++;
			res--;
		}
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimed;
	int			i;
	int			l;
	size_t		size;

	size = getsize(s1, set);
	trimed = malloc(sizeof(char) * (size + 1));
	if (trimed == 0)
		return (trimed);
	i = ft_strlen(s1) - 1;
	while (isset(s1[i], set) && i--)
		;
	l = 0;
	if (i >= 0 && s1[i])
	{
		while (s1[l] && isset(s1[l], set))
			l++;
	}
	ft_strncpy_until(trimed, &s1[l], i, l);
	return (trimed);
}

/* 	if ((unsigned long)i == (ft_strlen(s1) - 1))
		i++; */
/* int main()
{
	char *s1 = " lt ";
 	char *ret = ft_strtrim(s1, "l ");
	printf("\n%s", ret);
} */