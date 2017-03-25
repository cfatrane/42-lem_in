/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:24:41 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/25 17:43:12 by cfatrane         ###   ########.fr       */
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
	ft_printf("\n");
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
	t_path	*parcours;

	ants = 1;
	parcours = NULL;
	if (env->flag_entry != 1)
		print_data(env);
	if (env->flag_print == 1)
		ft_printlst(env);
	while (ants != env->ants + 1)
	{
		ft_push_back_path(&parcours, 0, ants, env->path->next->name);
		print_path(parcours);
		if (parcours->name == env->end_name)
			ft_path_delone_front(&parcours);
		move_ants_next(env, parcours);
		ants++;
	}
	while (ft_path_size(parcours) != 0)
	{
		print_path(parcours);
		if (parcours->name == env->end_name)
			ft_path_delone_front(&parcours);
		move_ants_next(env, parcours);
	}
}
