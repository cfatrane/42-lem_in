/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:24:41 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/25 14:21:59 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_path(t_path *parcours)
{
	t_path	*tmp;

	tmp = parcours;
	while (tmp)
	{
		ft_printf("L%d-%s", tmp->ants, tmp->name);
		if (tmp->next != NULL)
			ft_printf(" ");
		tmp = tmp->next;
	}
}

void	move_ants_next(t_lem_in *env, t_path *parcours)
{
	t_path	*tmp;
	t_path	*rev;

	tmp = env->path;
	rev = env->path;
	while (parcours)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->name, parcours->name) == 0)
			{
				parcours->name = tmp->next->name;
				break ;
			}
			tmp = tmp->next;
		}
		tmp = rev;
		parcours = parcours->next;
	}
}

void	move_ants(t_lem_in *env)
{
	int		ants;
	int		i;
	t_path	*parcours;
	t_path	*tmp;

	tmp = env->path;
	i = 0;
	ants = 1;
	parcours = NULL;
	ft_printf("\n");
	while (ants != env->ants + 1)
	{
		ft_push_back_path(&parcours, tmp->data, ants, env->path->next->name);
		print_path(parcours);
		if (parcours->name == env->end_name)
			ft_path_delone_front(&parcours);
		move_ants_next(env, parcours);
		ft_printf("\n");
		ants++;
	}
	while (ft_path_size(parcours) != 0)
	{
		print_path(parcours);
		if (parcours->name == env->end_name)
			ft_path_delone_front(&parcours);
		move_ants_next(env, parcours);
		ft_printf("\n");
	}
}
