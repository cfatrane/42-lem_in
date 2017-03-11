/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:08:21 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 19:31:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_is_links(t_lem_in *env, char *line)
{
	int	i;
	int	flag;
	t_rooms *tmp;

	i = 0;
	flag = 0;
	tmp = env->rooms;
	while (line[i] && line[i] != '-')
		i++;
	while (tmp)
	{
		if (ft_strncmp(line, tmp->name, i) == 0)
		{
			flag++;
			if (line[i] == '-')
			{
				i++;
				flag++;
			}
		}
		tmp = tmp->next;
	}
	tmp = env->rooms;
	while (tmp)
	{
		if (ft_strncmp(&line[i], tmp->name, ft_strlen(line) - i) == 0)
		{
			flag++;
			break ;
		}
		tmp = tmp->next;
	}
	if (flag == 3)
		return (1);
	return (0);
}
