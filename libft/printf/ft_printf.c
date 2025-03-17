/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:31:40 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/20 10:48:08 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_args(char c, int *len, va_list	list)
{
	if (c == 'c')
		ft_putchar(va_arg(list, int), len);
	else if (c == 's')
		ft_putstr(va_arg(list, char *), len);
	else if (c == 'p')
		ft_call_pa(va_arg(list, void *), len);
	else if (c == 'd')
		ft_putnbr(va_arg(list, int), len);
	else if (c == 'i')
		ft_putnbr(va_arg(list, int), len);
	else if (c == 'u')
		ft_print_uint(va_arg(list, unsigned int), len);
	else if (c == 'X')
		ft_hexa_up(va_arg(list, unsigned int), len);
	else if (c == 'x')
		ft_hexa_down(va_arg(list, unsigned int), len);
	else if (c == '%')
		ft_putchar('%', len);
	return (*len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	list;

	if (format == NULL)
		return (-1);
	i = 0;
	len = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &len);
		else if (format[i] == '%')
		{
			i++;
			type_args(format[i], &len, list);
		}
		i++;
	}
	va_end(list);
	return (len);
}
