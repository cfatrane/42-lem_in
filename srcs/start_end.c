/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 09:56:15 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 20:05:06 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


int		ft_get_hash(t_rooms *rooms, char *name_ref)
{
	if (rooms == NULL)
		return (0);
	if (ft_strcmp(rooms->name, name_ref) == 0)
		return (rooms->hash);
	else if (rooms->next)
		return (ft_get_hash(rooms->next, name_ref));
	else
		return (0);
}
