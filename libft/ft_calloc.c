/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:46:47 by apouesse          #+#    #+#             */
/*   Updated: 2024/11/13 13:46:48 by apouesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated_array;
	size_t	i;

	allocated_array = 0;
	if (size && (nmemb > 2147483647 / size))
		return (allocated_array);
	allocated_array = malloc(nmemb * size);
	if (allocated_array == 0)
		return (allocated_array);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)allocated_array)[i] = 0;
		i++;
	}
	return (allocated_array);
}
