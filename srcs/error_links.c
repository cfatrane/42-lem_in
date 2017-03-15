/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:55:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/15 13:58:17 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_links(t_lem_in *env)
{
	return (0);
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
				return (1);
			}
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (0);
}