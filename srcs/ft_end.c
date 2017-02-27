/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:55:12 by cfatrane          #+#    #+#             */
/*   Updated: 2017/02/27 17:07:04 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_end(t_lem_in *env)
{
	char	*line;
	int		words;
	char	**data;

	ft_printf("\033[31mDEBUT END END END END END END\n\033[0m");
	while (get_next_line(0, &line))
	{
		ft_printf("\033[32mEND LINE = %s\n\033[0m", line);
		words = ft_count_words_sep(line, ' ');
//		if (words != 3)
//			return (-1);
		if (words == 3)
		{
			data =  ft_strsplit(line, ' ');
			env->rooms.name = data[0];
			env->rooms.coord_x = ft_atoi(data[1]);
			env->rooms.coord_y = ft_atoi(data[2]);
		ft_printf("Name END = %s Coord X = %d Coord Y = %d\n", env->rooms.name, env->rooms.coord_x, env->rooms.coord_y);
		}
	}
	ft_printf("\033[31mFIN END END END END END END\n\033[0m");
	return (0);
}
