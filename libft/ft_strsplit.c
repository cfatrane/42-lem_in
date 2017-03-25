/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:43:43 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/24 15:25:36 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		nb_words;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_count_words_sep(s, c);
	if (!(str = ft_strnew_two(1, nb_words)))
		return (NULL);
	while (nb_words--)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = ft_strlen_sep(s, c);
		str[i] = ft_strsub(s, 0, len);
		if (str[i] == '\0')
			return (NULL);
		s += ft_strlen_sep(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
