/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:33:17 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/12 13:34:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_start(t_lem_in *env, char *line)
{
	char	**data;
	int		words;

	env->flag_start = 1;
	(get_next_line(0, &line));
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

int		ft_rooms(t_lem_in *env, char *line)
{
	char	**data;
	int		words;

	env->flag_rooms = 1;
	words = ft_count_words_sep(line, ' ');
	if (words == 3)
	{
		data = ft_strsplit(line, ' ');
		if (ft_error_rooms(data[0], data[1], data[2]) == -1)
		{
			ft_printf("ERROR ROOMS\n");
			return (-1);
		}
		ft_rooms_push_back(&(env)->rooms, data[0], ft_atoll(data[1]),
				ft_atoll(data[2]));
		env->nb_rooms++;
	}
	else
	{
		ft_printf("ERROR ROOMS\n");
		return (-1);
	}
	return (0);
}

int		ft_end(t_lem_in *env, char *line)
{
	char	**data;
	int		words;

	env->flag_end = 1;
	(get_next_line(0, &line));
	words = ft_count_words_sep(line, ' ');
	if (words == 3)
	{
		data = ft_strsplit(line, ' ');
		if (ft_error_rooms(data[0], data[1], data[2]) == -1)
		{
			ft_printf("ERROR END\n");
			return (-1);
		}
		ft_rooms_push_back(&(env)->rooms, data[0], ft_atoll(data[1]),
				ft_atoll(data[2]));
		env->nb_rooms++;
	}
	else
	{
		ft_printf("ERROR END\n");
		return (-1);
	}
	return (0);
}
