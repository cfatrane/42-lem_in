/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:36:53 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/28 14:35:01 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strnew_two(size_t x, size_t y)
{
	char	**tab;
	char	*tableau2;
	size_t	i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * y);
	tableau2 = (char *)malloc(sizeof(char) * x * y);
	while (i < y)
	{
		tab[i] = &tableau2[i * x];
		i++;
	}
	return (tab);
}
