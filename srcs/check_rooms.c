/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:58:34 by cfatrane          #+#    #+#             */
/*   Updated: 2017/02/26 20:17:27 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_rooms(t_lem_in *env)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (*line == '#')
			ft_start(env);
	}
	return (0);
}
