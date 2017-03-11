/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:58:34 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 16:54:38 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// CHECK SALLE D ABORD AVEC START

int	check_rooms(t_lem_in *env)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
//		ft_printf("\033[34mCHECK ROOMS LINE = %s\n\033[0m", line);
		if (ft_strcmp(line, "##start") == 0)
		{
			(get_next_line(0, &line));
			if (ft_start(env, line) == -1)
				return (-1);
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			(get_next_line(0, &line));
			if (ft_end(env, line) == -1)
				return (-1);
		}
		else if (line[0] == '#' && line[1] != '#')
			ft_comment(env, line);
		else if (ft_is_links(env, line) == 1)
		{
			if (ft_links(env, line) == -1)
			{
				ft_printf("ERROR LINKS\n");
				return (-1);
			}
		}
		else if (1)
		{
			if (ft_rooms(env, line) == -1)
				return (-1);
		}
		else
		{
			ft_printf("NO START\n");
			return (-1);
		}
	}
	return (0);
}
