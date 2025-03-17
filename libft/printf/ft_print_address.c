/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:40:11 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/18 18:42:24 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_address(void *p, int *len)
{
	uintptr_t	address;
	int			digit;

	address = (uintptr_t) p;
	if (address == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	if (address >= 16)
	{
		ft_print_address((void *)(address / 16), len);
	}
	digit = address % 16;
	if (digit <= 9)
		ft_putchar(digit + '0', len);
	else
		ft_putchar(digit - 10 + 'a', len);
}

void	ft_call_pa(void *p, int *len)
{
	uintptr_t	address;

	address = (uintptr_t) p;
	if (address != 0)
		ft_putstr("0x", len);
	ft_print_address((void *)(address), len);
}
