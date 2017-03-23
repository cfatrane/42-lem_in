/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:20:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/23 18:39:06 by cfatrane         ###   ########.fr       */
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

void	ft_int_clear(t_int **elem)
{
	if (*elem != NULL)
	{
		ft_int_clear(&((*elem)->next));
		free(*elem);
		*elem = NULL;
	}
}

void	ft_free_tab_room(t_lem_in *env)
{
	int	i;

	i = 0;
	while (env->tab_rooms[i])
	{
		ft_rooms_clear(&(env->tab_rooms[i]));
		i++;
	}
	free(env->tab_rooms);
}

void	free_env(t_lem_in *env, t_tab *tab)
{
	ft_rooms_clear(&env->rooms);
	ft_free_tab_room(env);
	ft_int_clear(&env->elem);
	free(tab->color);
	free(tab->parent);
	free(tab->dist);
}
