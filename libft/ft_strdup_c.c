/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:56:36 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/26 21:40:04 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_c(const char *s1, char c)
{
	char	*s2;

	if (!(s2 = ft_strnew(ft_strlen_sep(s1, c))))
		return (NULL);
	ft_strcpy_c(s2, s1, c);
	return (s2);
}
