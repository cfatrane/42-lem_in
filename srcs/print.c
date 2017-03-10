/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:18:24 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/10 17:02:34 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	printlst(t_lem_in *env)
{
	t_rooms	**tmp1 = env->tab_rooms;
	t_rooms	*tmp2;
	int i = 0;

	while (tmp1[i])
	{
		ft_printf("%d: ", i);
		tmp2 = tmp1[i];
		while (tmp2)
		{
//			ft_printf("|%s| --> ", tmp2->name);
			ft_printf("||%s||%d %d %d| --> ", tmp2->name, tmp2->coord_x, tmp2->coord_y, tmp2->hash);
			tmp2 = tmp2->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	ft_rooms_display(t_lem_in *env)
{
	t_rooms	*tmp;

	tmp = env->rooms;
	while (tmp)
	{
		ft_printf("\033[31mName = %s Coord X = %d Coord Y = %d HASH = %d\n\033[0m", tmp->name, tmp->coord_x, tmp->coord_y, tmp->hash);
		tmp = tmp->next;
	}
}

void	test()
{
//	ft_printf("NUMBER = ");
/*	for (int y = 0 ; y < env->nb_rooms ; y++)
	{
		ft_printf("%d", y % 10);
	}*/
/*	t_rooms *tmp = env->rooms;
	while (tmp)
	{
		ft_printf("|%s|", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
	tmp = env->rooms;
	for (int i = 0 ; i < env->nb_rooms ; i++)
	{
		ft_printf("LINE %s = |", tmp->name);
		for (int j = 0 ; j < env->nb_rooms ; j++)
		{
			if (env->ant_farm[i][j] == '1')
				ft_printf("\033[31m%c\033[0m", env->ant_farm[i][j]);
			else
				ft_printf("%c", env->ant_farm[i][j]);
		}
		ft_printf("|\n");
		tmp = tmp->next;
	}*/
}
