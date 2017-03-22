/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:20:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/22 18:59:52 by cfatrane         ###   ########.fr       */
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

void	free_tab_room(t_lem_in *env)
{
	int	i;

	i = 0;
	while (env->tab_rooms[i])
	{
		ft_rooms_clear(&(env->tab_rooms[i]));
		i++;
	}
}

void	free_env(t_lem_in *env, t_tab *tab)
{
}
