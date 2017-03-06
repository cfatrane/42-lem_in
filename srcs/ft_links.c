/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:41:38 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/06 16:48:01 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_links(t_lem_in *env)
{
	char	**ant_farm;
	char	*line;

	if (!(ant_farm = ft_strnew_two(env->nb_rooms, env->nb_rooms)))
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		ft_printf("\033[33mLINKS LINE = %s\n\033[0m", line);
	}
	return (0);
}
