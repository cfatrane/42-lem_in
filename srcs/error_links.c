/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:55:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/16 11:02:47 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_check_links(t_lem_in *env, int hash1, int hash2)
{
	t_lstrooms	*tmp;

	tmp = env->tab_rooms[hash1];
	while (tmp)
	{
		if (tmp->hash == hash2)
			return (-1);
		tmp = tmp->next;
	}
	tmp = env->tab_rooms[hash1];
	while (tmp)
	{
		if (tmp->hash == hash1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
