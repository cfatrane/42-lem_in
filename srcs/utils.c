/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:57:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/09 19:41:38 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	error(void)
{
	ft_printf("ERROR\n");
	return (-1);
}

void	ft_rooms_display(t_lem_in *env)
{
	t_rooms	*tmp;

	tmp = env->rooms;
	while (tmp)
	{
		ft_printf("\033[31mName = %s Coord X = %d Coord Y = %d HASH = %d\n\033[0m", tmp->name, tmp->coord_x, tmp->coord_y, tmp->hash);
		tmp = tmp->next;
	}
}

int	tab_len(t_lem_in *env)
{
	int len;

	len = 0;
	(void)env;

	return (len);
}
t_rooms	*ft_rooms_find(t_rooms *rooms, int hash_ref)
{
	if (rooms == NULL)
		return (NULL);
	if (ft_nbrcmp(rooms->hash, hash_ref) == 0)
		return (rooms);
	else if (rooms->next)
		return (ft_rooms_find(rooms->next, hash_ref));
	else
		return (NULL);
}

t_rooms	*ft_rooms_sort(t_rooms *lst)
{
	int		tempo;
	t_rooms	*parcour;

	parcour = lst;
	while (lst->next)
	{
		if (lst->hash > lst->next->hash)
		{
			tempo = lst->hash;
			lst->hash = lst->next->hash;
			lst->next->hash = tempo;
			lst = parcour;
		}
		else
			lst = lst->next;
	}
	lst = parcour;
	return (lst);
}

void	printlst(t_lem_in *env)
{
	t_rooms	**tmp1 = env->tab_rooms;
	t_rooms	*tmp2;
	int i = 0;

	while (tmp1[i])
	{
		ft_printf("%d: ", i);
		tmp2 = tmp1[i];
		while (tmp2)
		{
			ft_printf("%d --> ", tmp2->hash);
			tmp2 = tmp2->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
