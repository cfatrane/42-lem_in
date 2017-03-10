/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:37:38 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/10 17:16:15 by cfatrane         ###   ########.fr       */
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
	rooms->hash = hachage_lst(name);
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

void	ft_rooms_push_front(t_rooms **stack, char *name, int coord_x, int coord_y)
{
	t_rooms*	list;

	list = ft_create_elem_rooms(name, coord_x, coord_y);
	if ((*stack))
		list->next = *stack;
	ft_printf("PAR LA\n");
	*stack = list;
}

t_rooms	*ft_create_rooms(ssize_t nbr)
{
	t_rooms	*stack;

	if (!(stack = (t_rooms*)malloc(sizeof(*stack))))
		return (NULL);
	stack->hash = nbr;
	stack->next = NULL;
	return (stack);
}

void	ft_stack_push_back(t_rooms **stack, ssize_t nbr)
{
	if (*stack)
	{
		if ((*stack)->next)
			ft_stack_push_back(&(*stack)->next, nbr);
		else
			(*stack)->next = ft_create_rooms(nbr);
	}
	else
		*stack = ft_create_rooms(nbr);
}
