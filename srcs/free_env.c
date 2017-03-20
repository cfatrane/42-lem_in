/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:20:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 18:58:28 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_rooms_clear(t_rooms **begin_list)
{
	if (*begin_list != NULL)
	{
		ft_rooms_clear(&((*begin_list)->next));
		free(*begin_list);
		*begin_list = NULL;
	}
}

void	free_env(t_lem_in *env, t_tab *tab)
{
	int	i;

	i = 0;
	while (env->tab_rooms[i])
	{
		ft_rooms_clear(&env->tab_rooms[i]);
		free(env->tab_rooms[i]);
		i++;
	}
	ft_rooms_clear(&env->rooms);
	free (tab->color);
	free (tab->dist);
	free (tab->parent);
	free (env->tab_rooms);
	free (env);
}
