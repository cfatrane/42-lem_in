/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:37:38 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 18:20:37 by cfatrane         ###   ########.fr       */
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

t_rooms	*ft_create_rooms(ssize_t nbr)
{
	t_rooms	*rooms;

	if (!(rooms = (t_rooms*)malloc(sizeof(*rooms))))
		return (NULL);
	rooms->hash = nbr;
	rooms->next = NULL;
	return (rooms);
}
