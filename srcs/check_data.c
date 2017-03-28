/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:27:05 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/26 20:51:56 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_ants(t_lem_in *env)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
	{
		if (ft_error_nbr(line) == -1)
			return (-1);
		env->ants = ft_atoll(line);
		if (env->ants <= 0)
			return (-1);
		ft_push_back_line(&env->data, line);
		free(line);
	}
	return (0);
}

int	check_links_rooms(t_lem_in *env, char *line)
{
	if ((line[0] == '#' && line[1] != '#') ||
			(line[0] == '#' && line[1] == '#'))
	{
	}
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

int	check_start_end(t_lem_in *env, char *line)
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
	else if (check_links_rooms(env, line) == -1)
		return (-1);
	return (0);
}

int	algo(t_lem_in *env, t_tab *tab)
{
	if (env->flag_start != 1 || env->flag_end != 1 || env->flag_path != 1)
		return (-1);
	env->flag_entry = 1;
	if (bfs(env->start_hash, env, tab) == -1)
		return (-1);
	return (0);
}

int	check_rooms(t_lem_in *env, t_tab *tab)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		ft_push_back_line(&env->data, line);
		if (ft_strcmp(line, "") == 0)
			return (algo(env, tab) == -1 ? -1 : 0);
		if (check_start_end(env, line) == -1)
		{
			if (ft_strcmp(line, "") == 0)
				return (algo(env, tab) == -1 ? -1 : 0);
			return (algo(env, tab) == -1 ? -1 : -1);
		}
		free(line);
	}
	return (0);
}
