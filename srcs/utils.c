/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:57:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 15:37:38 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

size_t	ft_rooms_size(t_rooms *stack)
{
	if (stack == NULL)
		return (0);
	return (ft_rooms_size(stack->next) + 1);
}

size_t	ft_int_size(t_int *stack)
{
	if (stack == NULL)
		return (0);
	return (ft_int_size(stack->next) + 1);
}

t_rooms	**ft_tab_rooms(int x, int y)
{
	int		i;
	t_rooms	**tab;

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

void	count_vertices(t_lem_in *env)
{
	t_rooms	**tabroom;
	t_rooms	*rooms;
	int		i;

	tabroom = env->tab_rooms;
	i = 0;
	while (i < (max_hash(env) + 1))
	{
		rooms = tabroom[i];
		if (rooms)
		{
			while (rooms)
			{
				env->nb_vertices++;
				break ;
				rooms = rooms->next;
			}
		}
		i++;
	}
}
