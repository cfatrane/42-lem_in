/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:55:12 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/07 13:41:27 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_end(t_lem_in *env)
{
	char	*line;
	int		words;
	char	**data;

	ft_printf("\033[31mDEBUT END END END END END END\n\033[0m");
	while (get_next_line(0, &line) > 0)
	{
		ft_printf("\033[32mEND LINE = %s TMP = %s\n\033[0m", line, env->line_tmp);
		env->line_tmp = line;
		if (line[0] == '#' && line[1] != '#')
			ft_comment(env);
		else if (1)
		{
			words = ft_count_words_sep(line, ' ');
			if (words == 3)
			{
				data =  ft_strsplit(line, ' ');
				if (ft_error(data[1]) == -1 || ft_error(data[2]) == -1)
				{
					ft_printf("ERROR COORD\n");
					return (-1);
				}
				ft_rooms_push_back(&(env->rooms), data[0], ft_atoll(data[1]), ft_atoll(data[2]));
				env->nb_rooms++;
			}
			else if (ft_is_links(line) == 1)
			{
				if (ft_links(env, line) == -1)
					return (-1);
				/*	i = 0;
				//	ft_printf("\033[31mFIN END END END END END END\n\n\033[0m");
				//				if (ft_links(env) == -1)
				//					return (-1);
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
				ft_printf("NBR = %d\n", nbr);*/
			}
		}
	}
	return (0);
}
