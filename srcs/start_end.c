/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 09:56:15 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/16 16:05:00 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	take_start(t_lem_in *env, char *name, int coord_x, int coord_y)
{
	env->start.name = name;
	env->start.coord_x = coord_x;
	env->start.coord_y = coord_y;
	env->start.hash = 0;
}

void	take_end(t_lem_in *env, char *name, int coord_x, int coord_y)
{
	env->end.name = name;
	env->end.coord_x = coord_x;
	env->end.coord_y = coord_y;
	env->end.hash = 0;
}
