/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:57:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/15 13:56:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	**ft_tab_rooms(int x, int y)
{
	t_rooms	**tab;
	int		i;

	if (!(tab = (t_rooms**)malloc(sizeof(**tab) * (y + 1))))
		return (NULL);
	i = 0;
	while (i < y)
	{
		tab[i] = (t_rooms*)malloc(sizeof(*tab) * (x + 1));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

t_rooms	*ft_lstcpy(t_rooms *dst, t_rooms *src)
{
	dst = ft_memalloc(sizeof(t_rooms));
	while (src)
	{
		dst->name = src->name;
		dst->coord_x = src->coord_x;
		dst->coord_y = src->coord_y;
		dst->hash = src->hash;
		dst->next = src->next;
		src = src->next;
		dst = dst->next;
	}
	return (dst);
}
