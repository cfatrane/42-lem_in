/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:37:22 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/26 20:36:29 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*oct1;
	unsigned char	*oct2;
	unsigned int	i;

	oct1 = (unsigned char*)dst;
	oct2 = (unsigned char*)src;
	i = 0;
	while (oct2[i] && i < n)
	{
		oct1[i] = oct2[i];
		if (oct1[i] == (unsigned char)c)
			return (&oct1[i] + 1);
		i++;
	}
	return (NULL);
}
