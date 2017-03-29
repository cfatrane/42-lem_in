/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:20:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/26 19:22:53 by cfatrane         ###   ########.fr       */
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

void	ft_data_clear(t_line **data)
{
	if (*data != NULL)
	{
		ft_data_clear(&((*data)->next));
		free((*data)->line);
		free(*data);
		*data = NULL;
	}
}

void	ft_path_clear(t_path **path)
{
	if (*path != NULL)
	{
		ft_path_clear(&((*path)->next));
		free(*path);
		*path = NULL;
	}
}

void	ft_free_tab_room(t_lem_in *env)
{
	int	i;

	i = 0;
	if (env->tab_rooms)
	{
		while (i < env->malloc)
		{
			if (env->tab_rooms[i] != NULL)
				ft_rooms_clear(&env->tab_rooms[i]);
			else
				i++;
		}
		free(env->tab_rooms);
	}
}

void	free_env(t_lem_in *env, t_tab *tab)
{
	ft_rooms_clear(&env->rooms);
	ft_data_clear(&env->data);
	ft_free_tab_room(env);
	ft_path_clear(&env->path);
	free(tab->color);
	free(tab->parent);
	free(tab->dist);
	free(tab);
	free(env);
}
