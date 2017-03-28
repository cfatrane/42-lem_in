/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:18:17 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/25 20:01:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_tabnew(size_t size)
{
	int	*str;

	if (!(str = (int*)malloc(sizeof(*str) * (size))))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
