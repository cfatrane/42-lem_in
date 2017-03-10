/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:14:13 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/10 17:24:20 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	hachage(t_lem_in *env, char *str)
{
//	ft_printf("HASH LINE = |%s|\n", str);
	if (ft_error(str) == 0)
		return (ft_atoi(str));
	int	hash;
	int	i;

	hash = 0;
	i = 0;
	while (str[i])
	{
		hash += str[i];
		i++;
	}
//	hash %= env->nb_rooms;
	hash %= 100;
	(void)env;
	return (hash);
}

int	search_hash(t_lem_in *env, char *str)
{
	(void)env;
	(void)str;
	return (0);
}

int	hachage_lst(char *str)
{
//	ft_printf("HASH LINE = |%s|\n", str);
	if (ft_error(str) == 0)
		return (ft_atoi(str));
	int	hash;
	int	i;

	hash = 0;
	i = 0;
	while (str[i])
	{
		hash += str[i];
		i++;
	}
//	hash %= env->nb_rooms;
	hash %= 100;
	return (hash);
}
