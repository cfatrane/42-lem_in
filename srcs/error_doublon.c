/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:02:32 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 18:43:43 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	delete_collision(t_lem_in *env)
{
	if (!env->flag_dbl)
	{
		ft_lstcpy(env->rooms, collision(env));
		while (check_doublon_hash(env) != 0)
			ft_modify_doublon(env->rooms);
	}
	env->flag_dbl = 1;
	env->malloc = max_hash(env) + 1;
}

t_rooms	*ft_modify_doublon(t_rooms *rooms)
{
	t_rooms	*dst;
	t_rooms	*tmp;

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

int		check_doublon_hash(t_lem_in *env)
{
	t_rooms	*tmp_1;
	t_rooms	*tmp_2;

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

int		check_doublon_name(t_lem_in *env)
{
	t_rooms	*tmp_1;
	t_rooms	*tmp_2;

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

int		check_doublon_coord(t_lem_in *env)
{
	t_rooms	*tmp_1;
	t_rooms	*tmp_2;

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
