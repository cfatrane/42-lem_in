/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:24:11 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/09 10:38:13 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	lem_in(t_lem_in *env)
{
	if (check_ants(env) == -1)
		return (-1);
	if (check_rooms(env) == -1)
		return (-1);
	if (env->flag_start != 1 || env->flag_end != 1 || env->flag_path != 1)
	{
		ft_printf("NO START OR END OR PATH\n");
		return (-1);
	}
	ft_printf("NUMBER = ");
/*	for (int y = 0 ; y < env->nb_rooms ; y++)
	{
		ft_printf("%d", y % 10);
	}*/
	t_rooms *tmp = env->rooms;
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
	}
	ft_printf("\nNBR ROOMS = %d\n", env->nb_rooms);
//	ft_rooms_display(env);
	return (0);
}
