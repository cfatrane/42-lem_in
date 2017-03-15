/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:57:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/15 11:27:08 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	*ft_lstcpy(t_rooms *dst, t_rooms *src)
{
	dst = ft_memalloc(sizeof(t_rooms));
	while (src)
	{
		dst->name = src->name;
		dst->coord_x = src->coord_x;
		dst->coord_y = src->coord_y;
		dst->hash = src->hash;
		dst->next = src->next;
		src = src->next;
		dst = dst->next;
	}
	return (dst);
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

int		ft_check_doublon(t_lem_in *env)
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
			{
		//		ft_printf("|%s - %d| |%s - %d|\n", tmp_1->name, tmp_1->hash, tmp_2->name, tmp_2->hash);
				return (1);
			}
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (0);

}
