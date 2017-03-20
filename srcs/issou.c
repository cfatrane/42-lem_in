/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issou.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:18:30 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 14:11:36 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	printtmp(t_int *queue);

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

void	ft_push_front_int(t_int **elem, int i)
{
	t_int	*list;

	list = ft_create_elem_int(i);
	if ((*elem))
		list->next = *elem;
	*elem = list;
}

void	ft_int_delone_back(t_int *elem)
{/*
	t_int	*tmp;
	t_int	*to_free;

	to_free = *stack;
	tmp = NULL;
	while (to_free->next)
	{
		tmp = to_free;
		to_free = to_free->next;
	}
	if (tmp != NULL)
		tmp->next = NULL;
	free(to_free);
*/
/*	t_int **tmp = elem;

	while ((*tmp)->next != NULL)
	{
		ft_printf("hamza = %d\n", (*tmp)->i);
		*tmp = (*tmp)->next;
	}*/
//	while ((*elem) != NULL)
	printtmp(elem);
	t_int *tmp;

	while (elem != NULL)
	{		
		ft_printf("content = %d\n", (elem)->i);
		if ((elem)->next->next == NULL)
		{
			tmp = elem;
			free(elem->next);
			ft_printf("TMP\n");
			printtmp(tmp);
			break ;
		}
		elem = (elem)->next;
	}
	ft_printf("ISSOU\n");
	printtmp(elem);
//	(*elem)->next = NULL;
//	free(*elem);
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

int	ft_int_last(t_int *begin_list)
{
	if (begin_list == NULL)
		return (0);
	if (begin_list->next)
		return (ft_int_last(begin_list->next));
	else
		return (begin_list->i);
}

int	ft_int_first(t_int *elem)
{
	int	i = 0;

//	list = ft_create_elem_int(i);
	if (elem)
		i = elem->i;
	return (i);
}
