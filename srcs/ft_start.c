/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 20:17:40 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 18:23:08 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_start(t_lem_in *env, char *line)
{
	char	**data;
	int		words;

	env->flag_start = 1;
	words = ft_count_words_sep(line, ' ');
	if (words == 3)
	{
		data = ft_strsplit(line, ' ');
		if (ft_error_rooms(data[0], data[1], data[2]) == -1)
		{
			ft_printf("ERROR START\n");
			return (-1);
		}
		ft_rooms_push_back(&(env)->rooms, data[0], ft_atoll(data[1]),
				ft_atoll(data[2]));
		env->nb_rooms++;
	}
	else
	{
		ft_printf("ERROR START\n");
		return (-1);
	}
	return (0);
}
