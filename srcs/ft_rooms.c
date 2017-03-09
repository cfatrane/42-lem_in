/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:07:53 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/08 10:07:10 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_rooms(t_lem_in *env, char *line)
{
	char	**data;
	int		words;
	int		flags;

	flags = 0;
//	env->rooms = NULL;
	ft_printf("\033[31mDEBUT ROOMS ROOMS ROOMS ROOMS ROOMS ROOMS \n\033[0m");
	/*	if (flags == 0 && line) GERER LE CAS OU MERDE AVANT OU DIRECT APRES START
		return (-1);
		flags++;*/
	ft_printf("\033[33mROOMS LINE = %s\n\033[0m", line);
/*	if (ft_strcmp(line, "##end") == 0)
	{
		if (ft_end(env) == -1)
			return (-1);
	}
	else if (line[0] == '#' && line[1] != '#')
		ft_comment(env);
	//	else if (!(ft_strcmp(line, "##end") == 0) && !(line[0] == '#' && line[1] != '#'))
*/	if (1)
	{
		words = ft_count_words_sep(line, ' ');
		data = ft_strsplit(line, ' ');
		if (words == 3)
		{
			if (data[0][0] == 'L' || ft_error(data[1]) == -1 || ft_error(data[2]) == -1)
			{
				ft_printf("ERROR COORD\n");
				return (-1);
			}
//			ft_printf("DATA 0 = %s DATA 2 = %s DATA 3 = %s\n", data[0], data[1], data[2]);
			ft_rooms_push_back(&(env)->rooms, data[0], ft_atoll(data[1]), ft_atoll(data[2]));
			env->nb_rooms++;
		//	free(data);
		}
		else
		{
			ft_printf("ERROR ROOMS\n");
			return (-1);
		}
	}
	env->line_tmp = line;
	ft_printf("\033[31mFIN ROOMS ROOMS ROOMS ROOMS ROOMS ROOMS \n\n\033[0m");
	return (0);
}

