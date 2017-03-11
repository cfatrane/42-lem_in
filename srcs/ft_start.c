/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 20:17:40 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 16:57:03 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_start(t_lem_in *env, char *line)
{
	char	**data;
	int		words;

//	env->rooms = NULL;
	if (1)
	{
		env->flag_start = 1;
		words = ft_count_words_sep(line, ' ');
		data = ft_strsplit(line, ' ');
		if (words == 3)
		{
			if (ft_check_format_name(data[0]) == -1 || ft_error(data[1]) == -1 || ft_error(data[2]) == -1)
			{
				ft_printf("ERROR START\n");
				return (-1);
			}
			ft_rooms_push_back(&(env)->rooms, data[0], ft_atoll(data[1]), ft_atoll(data[2]));
			env->nb_rooms++;
		}
		else
		{
			ft_printf("ERROR START\n");
			return (-1);
		}
	}
	return (0);
}
