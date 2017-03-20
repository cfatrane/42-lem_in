/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issou.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:18:30 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 15:57:51 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_int	*ft_create_elem_int(int i)
{
	t_int	*elem;

	if (!(elem = (t_int*)malloc(sizeof(*elem))))
		return (NULL);
	elem->i = i;
	elem->next = NULL;
	return (elem);
}

void	ft_push_back_int(t_int **elem, int i)
{
	if (*elem)
	{
		if ((*elem)->next)
			ft_push_back_int(&(*elem)->next, i);
		else
			(*elem)->next = ft_create_elem_int(i);
	}
	else
		*elem = ft_create_elem_int(i);
}

void	ft_int_delone_front(t_int **stack)
{
	t_int	*to_free;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	if ((*stack) != NULL)
	{
		to_free = *stack;
		*(stack) = (*stack)->next;
		free(to_free);
	}
}

int		ft_int_last(t_int *begin_list)
{
	if (begin_list == NULL)
		return (0);
	if (begin_list->next)
		return (ft_int_last(begin_list->next));
	else
		return (begin_list->i);
}

int		ft_int_first(t_int *elem)
{
	int	i;

	i = 0;
	if (elem)
		i = elem->i;
	return (i);
}
