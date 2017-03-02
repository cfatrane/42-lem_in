/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:58:34 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/01 14:16:32 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_rooms(t_lem_in *env)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		ft_printf("\033[34mCHECK ROOMS LINE = %s\n\033[0m", line);
		if (ft_strcmp(line, "##start") == 0)
			ft_start(env);
		else if (ft_strcmp(line, "##end") == 0)
			ft_end(env);
		else if (*line == '#' && *line + 1 != '#')
			ft_comment(env);
	}
	return (0);
}
