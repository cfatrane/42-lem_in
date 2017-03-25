/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:51:09 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/25 15:21:47 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	lem_in(t_lem_in *env, t_tab *tab)
{
	if (check_ants(env) == -1)
		return (-1);
	if (check_rooms(env, tab) == -1)
		return (-1);
	if (env->flag_start != 1 || env->flag_end != 1 || env->flag_path != 1)
		return (-1);
	if (env->flag_entry != 1)
		if (bfs(env->start_hash, env, tab) == -1)
			return (-1);
	return (0);
}

int	active_flag(t_lem_in *env, int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "-v") == 0)
			env->flag_print = 1;
		else
		{
			ft_putendl_fd("ERROR", 2);
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_lem_in	*env;
	t_tab		*tab;

	if (!(env = ft_memalloc(sizeof(t_lem_in))))
	{
		ft_putendl_fd("ERROR", 2);
		return (-1);
	}
	if (!(tab = ft_memalloc(sizeof(t_tab))))
	{
		ft_putendl_fd("ERROR", 2);
		return (-1);
	}
	if (active_flag(env, argc, argv) == -1)
		return (-1);
	if (argc == 1 || env->flag_print == 1)
	{
		if (lem_in(env, tab) == -1)
		{
			ft_putendl_fd("ERROR", 2);
			return (-1);
		}
	}
	free_env(env, tab);
	return (0);
}
