/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:08:21 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 19:43:16 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	flag_one(t_lem_in *env, char *line, int *i)
{
	t_rooms *tmp;

	tmp = env->rooms;
	while (tmp)
	{
		if (ft_strncmp(line, tmp->name, *i) == 0)
		{
			env->flag_links++;
			if (line[*i] == '-')
			{
				(*i)++;
				env->flag_links++;
				break ;
			}
		}
		tmp = tmp->next;
	}
}

int		ft_is_links(t_lem_in *env, char *line)
{
	int		i;
	t_rooms *tmp;

	i = 0;
	tmp = env->rooms;
	env->flag_links = 0;
	while (line[i] && line[i] != '-')
		i++;
	if (line[i] == '\0')
		return (0);
	flag_one(env, line, &i);
	tmp = env->rooms;
	while (tmp)
	{
		if (ft_strncmp(&line[i], tmp->name, ft_strlen(line) - i) == 0)
		{
			env->flag_links++;
			break ;
		}
		tmp = tmp->next;
	}
	if (env->flag_links == 3)
		return (1);
	return (0);
}
