/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:35:21 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/18 14:10:15 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint(unsigned int n, int *len)
{
	if (n <= 9)
		ft_putchar(n + '0', len);
	else
	{
		ft_print_uint(n / 10, len);
		ft_print_uint(n % 10, len);
	}
}
