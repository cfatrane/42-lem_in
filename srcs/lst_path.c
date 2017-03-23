/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:27:25 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/23 19:57:32 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*ft_create_path_path(int data)
{
	t_path	*path;

	if (!(path = (t_path*)malloc(sizeof(*path))))
		return (NULL);
	path->data = data;
	path->next = NULL;
	return (path);
}

void	ft_push_back_path(t_path **path, int data)
{
	if (*path)
	{
		if ((*path)->next)
			ft_push_back_path(&(*path)->next, data);
		else
			(*path)->next = ft_create_path_path(data);
	}
	else
		*path = ft_create_path_path(data);
}

void	ft_push_front_path(t_path **path, int data)
{
	t_path	*list;

	list = ft_create_path_path(data);
	if ((*path))
		list->next = *path;
	*path = list;
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

int		ft_path_first(t_path *path)
{
	int	i;

	i = 0;
	if (path)
		i = path->data;
	return (i);
}
