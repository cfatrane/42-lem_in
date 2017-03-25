/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:18:24 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/24 11:24:54 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_rooms_display_name(t_rooms *rooms)
{
	t_rooms	*tmp;

	tmp = rooms;
	while (tmp)
	{
		ft_printf("\033[31m%s: \033[0m", tmp->name);
		break ;
		tmp = tmp->next;
	}
}

void	ft_printlst(t_lem_in *env)
{
	t_rooms	**tabroom;
	t_rooms	*rooms;
	t_rooms	*tmp;
	int		i;

	tabroom = env->tab_rooms;
	i = 0;
	ft_printf("\n");
	while (i < (max_hash(env) + 1))
	{
		ft_printf("%d: ", i);
		tmp = ft_rooms_find_hash(env->rooms, i);
		ft_rooms_display_name(tmp);
		rooms = tabroom[i];
		while (rooms)
		{
			ft_printf("|%s|", rooms->name);
			if (rooms->next != NULL)
				ft_printf(" --> ", rooms->name);
			rooms = rooms->next;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_rooms_display(t_rooms *rooms)
{
	t_rooms	*tmp;

	tmp = rooms;
	while (tmp)
	{
		ft_printf("\033[31mName = %s Coord X = %d Coord Y = %d HASH = \
				%d\n\033[0m", tmp->name, tmp->coord_x, tmp->coord_y, tmp->hash);
		tmp = tmp->next;
	}
}
