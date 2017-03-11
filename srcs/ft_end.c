/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:55:12 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 16:58:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_end(t_lem_in *env, char *line)
{
	int		words;
	char	**data;

//	env->line_tmp = line;
//	if (1)
//	{
		env->flag_end = 1;
		words = ft_count_words_sep(line, ' ');
		if (words == 3)
		{
			data =  ft_strsplit(line, ' ');
			if (ft_check_format_name(data[0]) == -1 || ft_error(data[1]) == -1 || ft_error(data[2]) == -1)
			{
				ft_printf("ERROR END\n");
				return (-1);
			}
			ft_rooms_push_back(&(env)->rooms, data[0], ft_atoll(data[1]), ft_atoll(data[2]));
			env->nb_rooms++;
		}
//	}
	return (0);
}
