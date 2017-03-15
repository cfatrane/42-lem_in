/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:18:24 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/15 14:22:08 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	printlst(t_lem_in *env)
{
	t_rooms	**tabroom;
	t_rooms	*rooms;
	int		i;

	tabroom = env->tab_rooms;
	i = 0;
	while (i < (max_hash(env) + 1))
	{
		ft_printf("%d: ", i);
		rooms = tabroom[i];
		while (rooms)
		{
			ft_printf("|%s| --> ", rooms->name);
//			ft_printf("|%d| --> ", rooms->hash);
			rooms = rooms->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
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
	ft_printf("\n");
}
