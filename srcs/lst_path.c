/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:27:25 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/28 13:43:52 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*ft_create_path(int data, int ants, char *name)
{
	t_path	*path;

	if (!(path = (t_path*)malloc(sizeof(*path))))
		return (NULL);
	path->ants = ants;
	ft_printf("Adresse path->ants = %p pour Adresse = %p\n", path->ants, ants);
	path->data = data;
	ft_printf("Adresse path->data = %p pour Adresse = %p\n", path->data, ants);
	path->name = name;
	ft_printf("Adresse path->name = %p pour Adresse = %p\n", path->name, ants);
	path->next = NULL;
	return (path);
}

void	ft_push_back_path(t_path **path, int data, int ants, char *name)
{
	if (*path)
	{
		if ((*path)->next)
			ft_push_back_path(&(*path)->next, data, ants, name);
		else
			(*path)->next = ft_create_path(data, ants, name);
	}
	else
		*path = ft_create_path(data, ants, name);
}

void	ft_push_front_path(t_path **path, int data, int ants, char *name)
{
	t_path	*list;

	list = ft_create_path(data, ants, name);
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
