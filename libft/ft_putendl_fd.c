/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:23:34 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/16 14:23:35 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	a;
	int		i;

	i = 0;
	while (s[i])
	{
		a = s[i];
		write(fd, &a, sizeof(char) * 1);
		i++;
	}
	write(fd, "\n", sizeof(char) * 1);
}
