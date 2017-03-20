/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:51:09 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 16:36:36 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	lem_in(t_lem_in *env)
{
	t_tab	*tab;

	if (!(tab = ft_memalloc(sizeof(t_tab))))
	{
		ft_putendl_fd("ERROR", 2);
		return (-1);
	}
	if (check_ants(env) == -1)
		return (-1);
	if (check_rooms(env) == -1)
	{
		ft_printf("ERROR CHECK ROOMS\n");
		return (-1);
	}
	if (env->flag_start != 1 || env->flag_end != 1 || env->flag_path != 1)
	{
		ft_printf("NO START OR END OR PATH\n");
		return (-1);
	}
//	ft_printlst(env);
	ft_rooms_display(env->rooms);

	env->start_hash = ft_get_hash(env->rooms, env->start.name);
	env->end_hash = ft_get_hash(env->rooms, env->end.name);
	ft_printf("start = %d\n", env->start_hash);
	bfs(env->start_hash, env, tab);
	return (0);
}

int	main(void)
{
	t_lem_in	*env;

	if (!(env = ft_memalloc(sizeof(t_lem_in))))
	{
		ft_putendl_fd("ERROR", 2);
		return (-1);
	}
	if (lem_in(env) == -1)
	{
		ft_putendl_fd("ERROR", 2);
		return (-1);
	}
	free(env);
	return (0);
}
