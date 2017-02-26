/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:39:54 by cfatrane          #+#    #+#             */
/*   Updated: 2017/02/16 18:31:56 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atou(const char *str)
{
	unsigned long long	nb;
	unsigned long long	tmp;

	nb = 0;
	tmp = 0;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+')
		str++;
	while (ft_isdigit((int)*str))
	{
		tmp = tmp * 10 + *str - '0';
		str++;
		if (tmp < nb)
			return (0);
		nb = tmp;
	}
	return (nb);
}
