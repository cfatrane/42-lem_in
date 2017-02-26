/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:01:56 by cfatrane          #+#    #+#             */
/*   Updated: 2017/02/26 17:58:42 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_ants(t_lem_in *env)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_error(line) == -1)
		return (-1);
	env->ants = atoi(line);
	if (env->ants <= 0)
	{
		ft_printf("ERROR NEGATIF\n");
		return (-1);
	}
	ft_printf("Ants = %d\n", env->ants);
	return (0);
}
