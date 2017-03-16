/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:02:32 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/16 13:27:02 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

int			check_doublon_hash(t_lem_in *env)
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

int			check_doublon_name(t_lem_in *env)
{
	t_lstrooms	*tmp_1;
	t_lstrooms	*tmp_2;

	tmp_1 = env->rooms;
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		while (tmp_2)
		{
			if (tmp_1->name == tmp_2->name)
				return (-1);
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (0);
}

int			check_doublon_coord(t_lem_in *env)
{
	t_lstrooms	*tmp_1;
	t_lstrooms	*tmp_2;

	tmp_1 = env->rooms;
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		while (tmp_2)
		{
			if (tmp_1->coord_x == tmp_2->coord_x &&
					tmp_1->coord_y == tmp_2->coord_y)
				return (-1);
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (0);
}
