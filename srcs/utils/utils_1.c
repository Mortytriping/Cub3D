/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:41:30 by apouesse          #+#    #+#             */
/*   Updated: 2025/03/19 11:54:38 by abaroukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	err_msg(char *str)
{
	size_t	i;
	int		ret;

	i = 0;
	while (str && str[i])
	{
		ret = write(2, &str[i], 1);
		i++;
	}
	(void)ret;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free (array);
}
