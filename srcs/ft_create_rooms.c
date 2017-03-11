/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:37:38 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 19:06:59 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	*ft_create_elem_rooms(char *name, int x, int y)
{
	t_rooms	*rooms;

	if (!(rooms = (t_rooms*)malloc(sizeof(*rooms))))
		return (NULL);
	rooms->name = name;
	rooms->coord_x = x;
	rooms->coord_y = y;
	rooms->hash = hachage_lst(name);
	rooms->next = NULL;
	return (rooms);
}

void	ft_rooms_push_back(t_rooms **rooms, char *name, int x, int y)
{
	if (*rooms)
	{
		if ((*rooms)->next)
			ft_rooms_push_back(&(*rooms)->next, name, x, y);
		else
			(*rooms)->next = ft_create_elem_rooms(name, x, y);
	}
	else
		*rooms = ft_create_elem_rooms(name, x, y);
}

void	ft_rooms_clear(t_rooms **begin_list)
{
	if (*begin_list != NULL)
	{
		ft_rooms_clear(&((*begin_list)->next));
		free(*begin_list);
		*begin_list = NULL;
	}
}
