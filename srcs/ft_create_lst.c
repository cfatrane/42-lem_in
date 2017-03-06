/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:14:13 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/06 13:31:11 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	*ft_create_elem_rooms(char *name, int coord_x, int coord_y)
{
	t_rooms	*rooms;

	if (!(rooms = (t_rooms*)malloc(sizeof(*rooms))))
		return (NULL);
	rooms->name = name;
	rooms->coord_x = coord_x;
	rooms->coord_y = coord_y;
	rooms->next = NULL;
	return (rooms);
}

void	ft_rooms_push_back(t_rooms **rooms, char *name, int coord_x, int coord_y)
{
	if (*rooms)
	{
		if ((*rooms)->next)
			ft_rooms_push_back(&(*rooms)->next, name, coord_x, coord_y);
		else
			(*rooms)->next = ft_create_elem_rooms(name, coord_x, coord_y);
	}
	else
		*rooms = ft_create_elem_rooms(name, coord_x, coord_y);
}

void	ft_rooms_push_front(t_rooms **rooms, char *name, int coord_x, int coord_y)
{
	t_rooms*list;

	list = ft_create_elem_rooms(name, coord_x, coord_y);
	if ((*rooms))
		list->next = *rooms;
	*rooms = list;
}
