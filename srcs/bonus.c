/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:28:06 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/28 09:41:27 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		active_flag(t_lem_in *env, int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "-v") == 0)
		{
			env->flag_print_list = 1;
			return (0);
		}
		else if (ft_strcmp(argv[1], "-p") == 0)
		{
			env->flag_print_all = 1;
			return (0);
		}
		else if (ft_strcmp(argv[1], "-s") == 0)
		{
			env->flag_print_short = 1;
			return (0);
		}
		else
			return (-1);
	}
	return (0);
}

void	ft_print_shortest_path(t_lem_in *env)
{
	t_path	*tmp;

	tmp = env->path->next;
	ft_printf("\n");
	while (tmp)
	{
		ft_printf("%s", tmp->name);
		if (tmp->next != NULL)
			ft_printf(" --> ", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_print_path(t_lem_in *env, t_tab *tab, int src, int dest)
{
	if (src == dest)
		ft_printf("%s", ft_get_name(env->rooms, src));
	else if (tab->parent[dest] == -1)
		ft_printf("Il n'y a pas de chemin de %s vers %s",
				ft_get_name(env->rooms, src), ft_get_name(env->rooms, dest));
	else
	{
		ft_print_path(env, tab, src, tab->parent[dest]);
		ft_printf(" %s", ft_get_name(env->rooms, dest));
	}
}

void	ft_print_full_path(t_lem_in *env, t_tab *tab)
{
	int	i;

	i = env->start_hash;
	ft_printf("\n");
	if (env->flag_print_all == 1)
		while (i < env->malloc)
		{
			ft_printf("Chemin de %s vers %s : ", ft_get_name(env->rooms,
						env->start_hash), ft_get_name(env->rooms, i));
			ft_print_path(env, tab, env->start_hash, i);
			i++;
			ft_printf("\n");
		}
}
