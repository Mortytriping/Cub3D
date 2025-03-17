/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:03:23 by abaroukh          #+#    #+#             */
/*   Updated: 2024/11/18 18:40:23 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr(int nb, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_call_pa(void *p, int *len);
void	ft_hexa_up(unsigned int nb, int *len);
void	ft_hexa_down(unsigned int nb, int *len);
void	ft_print_uint(unsigned int n, int *len);

#endif
