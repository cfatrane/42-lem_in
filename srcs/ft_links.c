/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:41:38 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/06 19:07:26 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_links(t_lem_in *env, char *line)
{
	char	**ant_farm;
	int		i;

	if (!(ant_farm = ft_strnew_two(env->nb_rooms, env->nb_rooms)))
		return (-1);
	i = 0;
	int nbr = ft_atoi(line);
	ft_printf("NBR = %d\n", nbr);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	if (!ft_isdigit(line[i]))
	{
		ft_printf("NO DIGIT\n");
		return (-1);
	}
	nbr = ft_atoi(&line[i]);
	ft_printf("NBR = %d\n", nbr);
	/*	while (get_next_line(0, &line) > 0)
		{
		i = 0;
		ft_printf("\033[32mLINKS LINE = %s TMP = %s\n\033[0m", line, env->line_tmp);
		if (line[0] == '#' && line[1] != '#')
		ft_comment(env);
		else if (1)
		{
		int nbr = ft_atoi(line);
		ft_printf("NBR = %d\n", nbr);
		while (ft_isdigit(line[i]))
		{
		i++;
		}
		i++;
		if (!ft_isdigit(line[i]))
		{
		ft_printf("NO DIGIT\n");
		return (-1);
		}
		nbr = ft_atoi(&line[i]);
		ft_printf("NBR = %d\n", nbr);
		}
		}*/
	return (0);
}
