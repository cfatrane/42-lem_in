/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:36:53 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/24 15:34:17 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strnew_two(size_t x, size_t y)
{
	char	**ptr;
	size_t	i;

	ptr = (char**)malloc(sizeof(*ptr) * (y + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < y - 1)
	{
		ptr[i] = (char*)malloc(sizeof(**ptr) * (x + 1));
		if (ptr[i] == NULL)
			return (NULL);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
