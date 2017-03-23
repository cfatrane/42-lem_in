/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:36:34 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/23 15:53:48 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel_two(char **ptr, int x, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		ptr[i] = (char*)malloc(sizeof(*(ptr[i])) * x);
		if (ptr[i] == NULL)
		{
			i = i - 1;
			while (i >= 0)
			{
				free(ptr[i]);
				i--;
			}
			free(ptr);
		}
		i++;
	}
}
