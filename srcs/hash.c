/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:14:13 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/25 18:43:25 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	*collision(t_lem_in *env)
{
	t_rooms	*tmp;

	tmp = env->rooms;
	while (tmp)
	{
		tmp->hash = hachage(env, tmp->name);
		tmp = tmp->next;
	}
	return (tmp);
}

int		hachage(t_lem_in *env, char *str)
{
	int	hash;
	int	i;

	hash = 0;
	i = 0;
	while (str[i])
	{
		hash += str[i] * ft_pow(str[i], i);
		i++;
	}
	hash %= env->nb_rooms;
	hash = ft_abs(hash);
	return (hash);
}

int		max_hash(t_lem_in *env)
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
