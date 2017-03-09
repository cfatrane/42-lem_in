/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:57:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/09 09:50:46 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	error(void)
{
	ft_printf("ERROR\n");
	return (-1);
}

void	ft_rooms_display(t_lem_in *env)
{
	t_rooms	*tmp;

	tmp = env->rooms;
	while (tmp)
	{
		ft_printf("\033[31mName = %s Coord X = %d Coord Y = %d\n\033[0m", tmp->name, tmp->coord_x, tmp->coord_y);
		tmp = tmp->next;
	}
}

int	tab_len(t_lem_in *env)
{
	int len;

	len = 0;
	(void)env;

	return (len);
}
