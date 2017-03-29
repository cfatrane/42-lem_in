/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:18:24 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/28 18:49:59 by cfatrane         ###   ########.fr       */
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
