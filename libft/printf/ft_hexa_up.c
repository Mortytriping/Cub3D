/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:35:24 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/18 16:57:36 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_up(unsigned int nb, int *len)
{
	if (nb >= 16)
	{
		ft_hexa_up(nb / 16, len);
		ft_hexa_up(nb % 16, len);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0', len);
		else
			ft_putchar((nb - 10) + 'A', len);
	}
}
