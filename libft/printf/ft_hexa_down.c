/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:35:26 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/18 17:22:42 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_down(unsigned int nb, int *len)
{
	if (nb >= 16)
	{
		ft_hexa_down(nb / 16, len);
		ft_hexa_down(nb % 16, len);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0', len);
		else
			ft_putchar((nb - 10) + 'a', len);
	}
}
