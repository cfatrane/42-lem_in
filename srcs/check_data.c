/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:27:05 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/14 12:39:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_ants(t_lem_in *env)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_error_nbr(line) == -1)
		return (-1);
	env->ants = atoi(line);
	if (env->ants <= 0)
	{
//		ft_printf("ERROR NEGATIF\n");
		return (-1);
	}
//	ft_printf("\033[31mAnts = %d\n\033[0m", env->ants);
	return (0);
}

int	check_links_rooms(t_lem_in *env, char *line)
{
	if (line[0] == '#' && line[1] != '#')
	{
	}
	else if (ft_is_links(env, line) == 1)
	{
//		ft_printf("DEBUG IS LINKS\n");
		if (ft_links(env, line) == -1)
		{
//			ft_printf("DEBUG LINKS\n");
			return (-1);
		}
	}
	else if (1)
	{
//		ft_printf("DEBUG ROOMS 1\n");
		if (ft_rooms(env, line) == -1)
		{
//			ft_printf("DEBUG ROOMS 2\n");
			return (-1);
		}
	}
	return (0);
}

int	check_start_end(t_lem_in *env, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
//		ft_printf("DEBUG START\n");
		if (ft_start(env, line) == -1)
			return (-1);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
//		ft_printf("DEBUG END\n");
		if (ft_end(env, line) == -1)
			return (-1);
	}
	else if (check_links_rooms(env, line) == -1)
		return (-1);
	return (0);
}

int	check_rooms(t_lem_in *env)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (check_start_end(env, line) == -1)
		{
			ft_printf("ERROR\n");
			return (-1);
		}
	}
	return (0);
}
