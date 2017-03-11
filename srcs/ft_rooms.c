/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:07:53 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 16:59:45 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_rooms(t_lem_in *env, char *line)
{
	char	**data;
	int		words;

//	if (1)
//	{
		env->flag_rooms = 1;
		words = ft_count_words_sep(line, ' ');
		data = ft_strsplit(line, ' ');
		if (words == 3)
		{
			if (ft_check_format_name(data[0]) == -1 || ft_error(data[1]) == -1 || ft_error(data[2]) == -1)
			{
				ft_printf("ERROR ROOMS\n");
				return (-1);
			}
			ft_rooms_push_back(&(env)->rooms, data[0], ft_atoll(data[1]), ft_atoll(data[2]));
			env->nb_rooms++;
		}
		else
		{
			ft_printf("ERROR ROOMS\n");
			return (-1);
		}
//	}
	env->line_tmp = line;
	return (0);
}

