/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:33:09 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/16 10:20:59 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lstrooms	*ft_create_elem_rooms(char *name, int x, int y)
{
	t_lstrooms	*rooms;

	if (!(rooms = (t_lstrooms*)malloc(sizeof(*rooms))))
		return (NULL);
	rooms->name = name;
	rooms->coord_x = x;
	rooms->coord_y = y;
	rooms->hash = 0;
	rooms->next = NULL;
	return (rooms);
}

void		ft_push_front_rooms(t_lstrooms **rooms, char *name, int x, int y)
{
	t_lstrooms	*list;

	list = ft_create_elem_rooms(name, x, y);
	if ((*rooms))
		list->next = *rooms;
	*rooms = list;
}

void		ft_push_back_rooms(t_lstrooms **rooms, char *name, int x, int y)
{
	if (*rooms)
	{
		if ((*rooms)->next)
			ft_push_back_rooms(&(*rooms)->next, name, x, y);
		else
			(*rooms)->next = ft_create_elem_rooms(name, x, y);
	}
	else
		*rooms = ft_create_elem_rooms(name, x, y);
}

void		ft_rooms_clear(t_lstrooms **begin_list)
{
	if (*begin_list != NULL)
	{
		ft_rooms_clear(&((*begin_list)->next));
		free(*begin_list);
		*begin_list = NULL;
	}
}

t_lstrooms	*ft_rooms_sort(t_lstrooms *lst)
{
	t_lstrooms	*parcour;

	parcour = lst;
	while (lst->next)
	{
		if (lst->hash > lst->next->hash)
		{
			ft_swap_str(&lst->name, &lst->next->name);
			ft_swap_int(&lst->coord_x, &lst->next->coord_x);
			ft_swap_int(&lst->coord_y, &lst->next->coord_y);
			ft_swap_int(&lst->hash, &lst->next->hash);
		}
		else
			lst = lst->next;
	}
	lst = parcour;
	return (lst);
}
