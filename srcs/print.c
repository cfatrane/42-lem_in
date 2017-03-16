/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:18:24 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/16 10:14:13 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_rooms_display_name(t_lstrooms *rooms)
{
	t_lstrooms	*tmp;

	tmp = rooms;
	while (tmp)
	{
		ft_printf("\033[31m%s: \033[0m", tmp->name);
		break ;
		tmp = tmp->next;
	}
}

void	printlst(t_lem_in *env)
{
	t_lstrooms	**tabroom;
	t_lstrooms	*rooms;
	t_lstrooms	*tmp;
	int			i;

	tabroom = env->tab_rooms;
	i = 0;
	while (i < (max_hash(env) + 1))
	{
		tmp = ft_rooms_find_hash(env->rooms, i);
		ft_rooms_display_name(tmp);
		rooms = tabroom[i];
		while (rooms)
		{
//			ft_printf("|%d| --> ", rooms->hash);
			ft_printf("|%s| --> ", rooms->name);
			rooms = rooms->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	ft_rooms_display(t_lstrooms *rooms)
{
	t_lstrooms	*tmp;

	tmp = rooms;
	while (tmp)
	{
		ft_printf("\033[31mName = %s Coord X = %d Coord Y = %d HASH = \
%d\n\033[0m", tmp->name, tmp->coord_x, tmp->coord_y, tmp->hash);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
