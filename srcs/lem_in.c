/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:24:11 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 15:25:53 by cfatrane         ###   ########.fr       */
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
//	t_rooms	**tmp1 = env->tab_rooms;
//	t_rooms	*tmp2;
//	int i = 0;
/*	while (i < env->nb_rooms)
	{
		ft_printf("%d: ", i);
		tmp2 = tmp1[i];
		while (tmp2)
		{
			ft_printf("%d --> ", tmp2->hash);
			tmp2 = tmp2->next;
		}
		ft_printf("\n");
		i++;
	}*/
	ft_printf("\nNBR ROOMS = %d\n", env->nb_rooms);
//	ft_rooms_display(env);
	printlst(env);
	return (0);
}
