/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:55:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/16 10:13:45 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_check_links(t_lem_in *env, int hash1, int hash2)
{
	t_lstrooms	*tmp;

	tmp = env->tab_rooms[hash1];
	while (tmp)
	{
		if (tmp->hash == hash2)
			return (-1);
		tmp = tmp->next;
	}
	tmp = env->tab_rooms[hash1];
	while (tmp)
	{
		if (tmp->hash == hash1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

t_lstrooms	*ft_modify_doublon(t_lstrooms *rooms)
{
	t_lstrooms	*dst;
	t_lstrooms	*tmp;

	dst = rooms;
	while (dst)
	{
		tmp = dst->next;
		while (tmp)
		{
			if (dst->hash == tmp->hash)
			{
				tmp->hash++;
				tmp = dst->next;
			}
			else
				tmp = tmp->next;
		}
		dst = dst->next;
	}
	return (dst);
}

int			ft_check_doublon(t_lem_in *env)
{
	t_lstrooms	*tmp_1;
	t_lstrooms	*tmp_2;

	tmp_1 = env->rooms;
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		while (tmp_2)
		{
			if (tmp_1->hash == tmp_2->hash)
				return (1);
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (0);
}
