/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:14:13 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/12 15:58:34 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** GERER COLLISION
*/

int	collision(t_lem_in *env)
{
	(void)env;
	return (0);
}

int	hachage_lst(char *str)
{
	int	hash;
	int	i;

	hash = 0;
	i = 0;
	while (str[i])
	{
		hash += (int)str[i];
		i++;
	}
	hash %= 100;
	return (hash);
}

int	search_hash(t_lem_in *env, char *str)
{
	(void)env;
	(void)str;
	return (0);
}

int	max_hash(t_lem_in *env)
{
	int		max;
	t_rooms	*tmp;

	tmp = env->rooms;
	max = tmp->hash;
	while (tmp)
	{
		if (tmp->hash > max)
			max = tmp->hash;
		tmp = tmp->next;
	}
	return (max);
}
