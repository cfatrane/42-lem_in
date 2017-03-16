/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:47:08 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/16 10:11:42 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lstrooms	*ft_rooms_find_hash(t_lstrooms *rooms, int hash_ref)
{
	if (rooms == NULL)
		return (NULL);
	if (ft_nbrcmp(rooms->hash, hash_ref) == 0)
		return (rooms);
	else if (rooms->next)
		return (ft_rooms_find_hash(rooms->next, hash_ref));
	else
		return (NULL);
}

t_lstrooms	*ft_rooms_find_name(t_lstrooms *rooms, char *name_ref)
{
	if (rooms == NULL)
		return (NULL);
	if (ft_strcmp(rooms->name, name_ref) == 0)
		return (rooms);
	else if (rooms->next)
		return (ft_rooms_find_name(rooms->next, name_ref));
	else
		return (NULL);
}
