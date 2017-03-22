/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:47:08 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/22 13:03:19 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	*ft_rooms_find_hash(t_rooms *rooms, int hash_ref)
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

t_rooms	*ft_rooms_find_name(t_rooms *rooms, char *name_ref)
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

char	*ft_get_name(t_rooms *rooms, int hash_ref)
{
	if (rooms == NULL)
		return (0);
	if (rooms->hash == hash_ref)
		return (rooms->name);
	else if (rooms->next)
		return (ft_get_name(rooms->next, hash_ref));
	else
		return (0);
}

int		ft_get_index(t_tab *tab, int nbr)
{
	int	i;

	i = 0;
	while (tab->parent[i] != nbr)
	{
		i++;
	}
	i = 1003;
	while (tab->parent[i] != nbr)
	{
//		ft_printf("hey = %d\n", );
		i--;
	}
	ft_printf("i = %d avec nbr = %d", i, nbr);
	return (i);
}
