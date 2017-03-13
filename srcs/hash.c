/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:14:13 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/13 16:01:27 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** GERER COLLISION
*/

t_rooms	*collision(t_lem_in *env)
{
	t_rooms *tmp;

	tmp = env->rooms;
	while (tmp)
	{
		tmp->hash = hachage_lst(env, tmp->name);
		tmp = tmp->next;
	}
	return (tmp);
}
/*
int	collision(t_lem_in *env)
{
	int		hash_tmp;
	t_rooms	*tmp_1;
	t_rooms	*tmp_2;

	tmp_1 = env->rooms;
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		hash_tmp = tmp_1->hash;
		while (tmp_2)
		{
			if (hash_tmp == tmp_2->hash)
			{
//				ft_printf("Name = %s avec Name = %s COLLISION\n", tmp_1->name, tmp_2->name);
//				return (-1);
			}
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (0);
}
*/
/*
int	re_hach(char *str)
{
	int	hash;

	hash = 0;
	return (hash);
}
*/
int	hachage_lst(t_lem_in *env, char *str)
{
	int	hash;
	int	i;

	hash = 0;
	i = 0;
	while (str[i])
	{
		hash += str[i] * pow(str[i], i);
		i++;
	}
	hash %= env->nb_rooms;
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
