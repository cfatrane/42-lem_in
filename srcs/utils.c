/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:57:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/14 13:08:59 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

t_rooms	*decol(t_rooms *lst)
{
//	int		tempo;
	t_rooms	*parcour;

	parcour = lst;
	while (lst->next)
	{
		if (lst->hash == lst->next->hash)
//		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			lst->hash++;
		/*	tempo = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tempo;*/
			lst = parcour;
		}
		else
			lst = lst->next;
	}
	lst = parcour;
	return (lst);
}
/*
   int		ft_modify(t_lem_in *env)
   {
   t_rooms	*tmp_1;
   t_rooms	*tmp_2;
   t_rooms	*tmp_3;

   tmp_1 = env->rooms;
   tmp_3 = env->rooms;
   while (tmp_1)
   {
   tmp_2 = tmp_1->next;
   while (tmp_2)
   {
   if (tmp_1->hash == tmp_2->hash)
   {
   ft_printf("|%s - %d| |%s - %d|\n", tmp_1->name, tmp_1->hash, tmp_2->name, tmp_2->hash);
//		tmp_2->hash++;
//		break ;
//				return (-1);
}
if (tmp_2->next == NULL)
break ;
tmp_2 = tmp_2->next;
}
//		ft_printf("|%s - %d|\n", tmp_1->name, tmp_1->hash);
tmp_1 = tmp_1->next;
}
return (0);
}*/
