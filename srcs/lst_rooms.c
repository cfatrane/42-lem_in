/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:33:09 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/28 13:09:47 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	*ft_create_elem_rooms(char *name, char *x, char *y)
{
	t_rooms	*rooms;

	if (!(rooms = (t_rooms*)malloc(sizeof(*rooms))))
		return (NULL);
	if (!(rooms->name = ft_strdup(name)))
		return (NULL);
	ft_printf("Adresse rooms->name = %p pour Adresse = %p\n", rooms->name, name);
	rooms->coord_x = ft_atoll(x);
	ft_printf("Adresse rooms->coord_x = %p pour Adresse = %p\n", rooms->coord_x, x);
	rooms->coord_y = ft_atoll(y);
	ft_printf("Adresse rooms->coord_y = %p pour Adresse = %p\n", rooms->coord_y, y);
	rooms->hash = 0;
	rooms->next = NULL;
	return (rooms);
}
/*
void	ft_push_front_rooms(t_rooms **rooms, char *name, int x, int y)
{
	t_rooms	*list;

	list = ft_create_elem_rooms(name, x, y);
	if ((*rooms))
		list->next = *rooms;
	*rooms = list;
}
*/
void	ft_push_back_rooms(t_rooms **rooms, char *name, char *x, char *y)
{
	if (*rooms)
	{
		if ((*rooms)->next)
			ft_push_back_rooms(&(*rooms)->next, name, x, y);
		else
			(*rooms)->next = ft_create_elem_rooms(name, x, y);
	}
	else
	{
		*rooms = ft_create_elem_rooms(name, x, y);
//		free(name);
	}
}

t_rooms	*ft_rooms_sort(t_rooms *lst)
{
	t_rooms	*parcour;

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

t_rooms	*ft_lstcpy(t_rooms *dst, t_rooms *src)
{
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
