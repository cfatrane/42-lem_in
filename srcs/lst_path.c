/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:27:25 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/23 19:36:47 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*ft_create_elem_path(int data)
{
	t_path	*elem;

	if (!(elem = (t_path*)malloc(sizeof(*elem))))
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_push_back_path(t_path **elem, int data)
{
	if (*elem)
	{
		if ((*elem)->next)
			ft_push_back_path(&(*elem)->next, data);
		else
			(*elem)->next = ft_create_elem_path(data);
	}
	else
		*elem = ft_create_elem_path(data);
}

void	ft_push_front_path(t_path **elem, int data)
{
	t_path	*list;

	list = ft_create_elem_path(data);
	if ((*elem))
		list->next = *elem;
	*elem = list;
}

void	ft_path_delone_front(t_path **stack)
{
	t_path	*to_free;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	if ((*stack) != NULL)
	{
		to_free = *stack;
		*(stack) = (*stack)->next;
		free(to_free);
	}
}

int		ft_path_first(t_path *elem)
{
	int	i;

	i = 0;
	if (elem)
		i = elem->data;
	return (i);
}
