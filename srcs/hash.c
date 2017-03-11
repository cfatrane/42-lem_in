/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:14:13 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 16:53:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	search_hash(t_lem_in *env, char *str)
{
	(void)env;
	(void)str;
	return (0);
}

int	hachage_lst(char *str)
{
//	if (ft_error(str) == 0)
//		return (ft_atoi(str));
	int	hash;
	int	i;

	hash = 0;
	i = 0;
	while (str[i])
	{
		hash += str[i];
		i++;
	}
	hash %= 100;
	return (hash);
}

