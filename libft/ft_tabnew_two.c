/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:22:42 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/24 16:11:03 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_tabnew_two(size_t x, size_t y)
{
	int		**ptr;
	size_t	i;

	ptr = (int**)malloc(sizeof(*ptr) * (y + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < y - 1)
	{
		ptr[i] = (int*)malloc(sizeof(**ptr) * (x + 1));
		if (ptr[i] == NULL)
			return (NULL);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
