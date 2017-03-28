/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:44:27 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/26 16:13:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if ((!s) || (!(str = ft_strnew(len))))
		return (NULL);
	while (s[start] != '\0' && len--)
	{
		str[start] = s[start];
		start++;
	}
	str[start] = '\0';
	return (str);
}
