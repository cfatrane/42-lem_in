/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:20:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/23 19:34:29 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_rooms_clear(t_rooms **rooms)
{
	if (*rooms != NULL)
	{
		ft_rooms_clear(&((*rooms)->next));
		free(*rooms);
		*rooms = NULL;
	}
}

void	ft_path_clear(t_path **elem)
{
	if (*elem != NULL)
	{
		ft_path_clear(&((*elem)->next));
		free(*elem);
		*elem = NULL;
	}
}

void	ft_free_tab_room(t_lem_in *env)
{
	int	i;

	i = 0;
	if (env->tab_rooms)
	{
		while (env->tab_rooms[i])
		{
			if (env->tab_rooms[i])
				ft_rooms_clear(&(env->tab_rooms[i]));
			else
				i++;
		}
	}
	free(env->tab_rooms);
}

void	free_env(t_lem_in *env, t_tab *tab)
{
	ft_rooms_clear(&env->rooms);
	ft_free_tab_room(env);
	ft_path_clear(&env->elem);
	free(tab->color);
	free(tab->parent);
	free(tab->dist);
}
