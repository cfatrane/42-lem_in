/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:58:34 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 19:02:46 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	links_rooms(t_lem_in *env, char *line)
{
	if (line[0] == '#' && line[1] != '#')
		ft_comment(env, line);
	else if (ft_is_links(env, line) == 1)
	{
		if (ft_links(env, line) == -1)
			return (-1);
	}
	else if (1)
	{
		if (ft_rooms(env, line) == -1)
			return (-1);
	}
	return (0);
}

int	start_end(t_lem_in *env, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (ft_start(env, line) == -1)
			return (-1);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (ft_end(env, line) == -1)
			return (-1);
	}
	else if (links_rooms(env, line) == -1)
		return (-1);
	return (0);
}

int	check_rooms(t_lem_in *env)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (start_end(env, line) == -1)
		{
			ft_printf("ERROR\n");
			return (-1);
		}
	}
	return (0);
}
