/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 20:17:40 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/01 14:15:52 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_start(t_lem_in *env)
{
	char	*line;
	int		words;
	char	**data;

	ft_printf("\033[31mDEBUT START START START START START START\n\033[0m");
	while (get_next_line(0, &line))
	{
		ft_printf("\033[33mSTART LINE = %s\n\033[0m", line);
		if (ft_strcmp(line, "##end") == 0)
			ft_end(env);
		//		if (*line == '#')
		//			return (ft_comment(env));
		words = ft_count_words_sep(line, ' ');
		//		if (words != 3 && (*line != '#'))
		//			return (-1);
		data = ft_strsplit(line, ' ');
		if (words == 3)
		{
			//ft_printf("DATA 0 = %s DATA 2 = %s DATA 3 = %s\n", data[0], data[1], data[2]);
			env->rooms.name = data[0];
			env->rooms.coord_x = ft_atoi(data[1]);
			env->rooms.coord_y = ft_atoi(data[2]);
		ft_printf("Name BEGIN = %s Coord X = %d Coord Y = %d\n", env->rooms.name, env->rooms.coord_x, env->rooms.coord_y);
		}
	}
	ft_printf("\033[31mFIN START START START START START START\n\033[0m");
	return (0);
}
