/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:03:30 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/15 11:14:41 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	while (((nptr[i] <= 13) && (nptr[i] >= 9)) || (nptr[i] == 32))
	{
		i++;
	}
	if (nptr[i] == '-')
		sign = -1;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
		i++;
	while ((nptr[i] <= '9' ) && (nptr[i] >= '0'))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
