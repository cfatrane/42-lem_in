/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:57:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 20:07:10 by cfatrane         ###   ########.fr       */
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

t_rooms	*ft_lstcpy(t_rooms *dst, t_rooms *src)
{
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
