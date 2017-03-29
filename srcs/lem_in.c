/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:51:09 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/28 19:08:24 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	return_error(void)
{
	ft_putendl_fd("ERROR", 2);
	return (-1);
}

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

int	main(int argc, char **argv)
{
	t_lem_in	*env;
	t_tab		*tab;

	if (!(env = ft_memalloc(sizeof(t_lem_in))))
		return (return_error());
	if (!(tab = ft_memalloc(sizeof(t_tab))))
		return (return_error());
	if (active_flag(env, argc, argv) == -1)
		return (return_error());
	if (argc == 1 || env->flag_print_list == 1 || env->flag_print_short == 1 ||
			env->flag_print_all == 1)
		if (lem_in(env, tab) == -1)
			return (return_error());
	if (env->flag_print_short == 1)
		ft_print_shortest_path(env);
	if (env->flag_print_list == 1)
		ft_printlst(env);
	if (env->flag_print_all == 1)
		ft_print_full_path(env, tab);
	free_env(env, tab);
	return (0);
}
