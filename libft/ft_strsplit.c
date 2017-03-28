/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:43:43 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/26 20:31:04 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	nb_words;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_count_words_sep(s, c);
	if (!(str = (char**)malloc(sizeof(char**) * (nb_words + 1))))
		return (NULL);
	while (i < nb_words)
	{
		while (*s != '\0' && *s == c)
			s++;
		if (!(str[i] = ft_strdup_c(s, ' ')))
			return (NULL);
		if (str[i] == '\0')
			return (NULL);
		s = s + ft_strlen_sep(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
