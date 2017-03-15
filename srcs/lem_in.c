/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:51:09 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/15 13:51:11 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	lem_in(t_lem_in *env)
{
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
	printlst(env);
//	ft_rooms_display(env->rooms);
//	bfs(48, env);
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
