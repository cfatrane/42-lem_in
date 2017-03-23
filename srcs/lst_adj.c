/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_adj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:19:22 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/23 19:18:31 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	*ft_create_elem_rooms_tab(t_rooms *src, int hash)
{
	t_rooms	*rooms;

	if (!(rooms = (t_rooms*)malloc(sizeof(*rooms))))
		return (NULL);
	rooms->name = src->name;
	rooms->coord_x = src->coord_x;
	rooms->coord_y = src->coord_y;
	rooms->hash = hash;
	rooms->next = NULL;
	return (rooms);
}

void	ft_push_front_tab(t_rooms **rooms, t_rooms *src, int hash)
{
	t_rooms	*list;

	if (!(list = ft_create_elem_rooms_tab(src, hash)))
		return ;
	if ((*rooms))
		list->next = *rooms;
	*rooms = list;
}

void	ft_push_back_tab(t_rooms **rooms, t_rooms *src, int hash)
{
	if (*rooms)
	{
		if ((*rooms)->next)
			ft_push_back_tab(&(*rooms)->next, src, hash);
		else
			(*rooms)->next = ft_create_elem_rooms_tab(src, hash);
	}
	else
		*rooms = ft_create_elem_rooms_tab(src, hash);
}
