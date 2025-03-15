/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:46:48 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/15 18:46:50 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	siz_o_grepint(int n, int size)
{
	int	len;

	len = 1;
	if ((n == -2147483648) && (size == 1))
		return (11);
	else if ((n == -2147483648) && (size == 0))
		return (10);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	if (size == 1)
		return (len);
	return (n);
}

static int	isnegative(int *n, char *itoa, int *i, int *size)
{
	int		x;
	char	*str;

	str = "-2147483648";
	x = 0;
	if (*n == -2147483648)
	{
		while (str[x])
		{
			itoa[x] = str[x];
			x++;
		}
		itoa[x] = '\0';
		return (-1);
	}
	if (*n < 0)
	{
		*n = *n * -1;
		itoa[0] = '-';
		*size = (siz_o_grepint(*n, 1) + 1);
		*i = 1;
		return (1);
	}
	return (0);
}

static int	stc_power(int nb, int power)
{
	int	n;
	int	i;

	n = nb;
	i = 0;
	if (power <= 0)
		return (1);
	if (power == 1)
		return (nb);
	while (i < (power - 1))
	{
		n = nb * n;
		i++;
	}
	return (n);
}

static int	setzero(int nb, char *itoa, int i)
{
	int	u;
	int	res;
	int	nb2;

	u = 0;
	res = 0;
	nb2 = nb - (stc_power(10, siz_o_grepint(nb, 1) - 1) * siz_o_grepint(nb, 0));
	while ((siz_o_grepint(nb2, 1) + u) < (siz_o_grepint(nb, 1) - 1))
	{
		itoa[i] = '0';
		u++;
		i++;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		i;
	int		nb;
	int		size;

	size = siz_o_grepint(n, 1);
	itoa = malloc(size + 1);
	if (itoa == 0)
		return (itoa);
	i = 0;
	if (isnegative(&n, itoa, &i, &size) == -1)
		return (itoa);
	nb = n;
	while (i < size)
	{
		itoa[i] = ('0' + siz_o_grepint(nb, 0));
		i++;
		i += setzero(nb, itoa, i);
		nb -= stc_power(10, siz_o_grepint(nb, 1) - 1) * siz_o_grepint(nb, 0);
	}
	itoa[i] = '\0';
	return (itoa);
}

/* int main()
{
	char *res = ft_itoa(-10004);
    printf("\n%s", res);
    free(res);
} */