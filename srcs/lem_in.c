/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:24:11 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/06 17:38:05 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	lem_in(t_lem_in *env)
{
	if (check_ants(env) == -1)
		return (-1);
	if (check_rooms(env) == -1)
		return (-1);
	ft_rooms_display(env);
	ft_printf("NBR ROOMS = %d\n", env->nb_rooms);
	return (0);
}
