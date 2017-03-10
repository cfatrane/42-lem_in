/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:55:01 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/10 09:50:12 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*
   int	error_rooms(t_lem_in *env)
   {
   return (0);
   }

   int	parcours_list(t_rooms **tab_rooms)
   {
   return (0);
   }
   */
int	parcours_hash(t_lem_in *env)
{
	int	i;

	i = 0;
	t_rooms	*tmp;

	while (env->tab_rooms[i])
	{
		tmp = env->tab_rooms[i];
		while (tmp)
		{
			ft_printf("room = %s", tmp->name);
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

/*
 *
 *
 *
 *
 *
 * TRIER LES SALLES PAS QUE LES HASH DANS SORT LIST
 *
 *
 *
 *
 *
 */

void	put_in_tab(t_lem_in *env, int hash1, int hash2)
{
	int i = 0;

	(void)hash2;
	//	t_rooms	*rooms = NULL;
	//	t_rooms	*tmp;
	t_rooms	*to_push1;
	t_rooms	*to_push2;
	//	(void)to_push1;
	while (1)
	{
		//		ft_printf("i = %d\n", i);
		if (i == hash1/* || i == hash2*/)
		{
			ft_printf("hash 1 = %d hash 2 = %d i = %d\n", hash1, hash2, i);
			//	ft_printf("\033[31mDEBUT LINKS ROOMS ROOMS ROOMS ROOMS ROOMS ROOMS \n\033[0m");
			to_push2 = ft_rooms_find(env->rooms, hash1);
			to_push1 = ft_rooms_find(env->rooms, hash2);
			//			ft_rooms_push_back(&(env)->rooms, to_push1->name, to_push1->coord_x, to_push1->coord_y);
			//			env->tab_rooms[i] = ft_rooms_find(env->rooms, hash1);
			//	if (hash2 > hash1)
			t_rooms	*tmp;

			tmp = to_push1;
			ft_printf("At rooms %d: %d\n", hash1, hash2);
			while (tmp)
			{
				ft_printf("\033[31mName = %s Coord X = %d Coord Y = %d HASH = %d\n\033[0m", tmp->name, tmp->coord_x, tmp->coord_y, tmp->hash);
				tmp = tmp->next;
			}
			tmp = to_push2;
			ft_printf("At rooms %d: %d\n", hash2, hash1);
			while (tmp)
			{
				ft_printf("\033[31mName = %s Coord X = %d Coord Y = %d HASH = %d\n\033[0m", tmp->name, tmp->coord_x, tmp->coord_y, tmp->hash);
				tmp = tmp->next;
			}
			ft_printf("\033[31mICI 1\n\033[0m");
			ft_rooms_push_back(&(env)->tab_rooms[hash1], to_push1->name, to_push1->coord_x, to_push1->coord_y);
			printlst(env);
			ft_printf("\033[32mICI 2\n\033[0m");
			ft_rooms_push_back(&(env)->tab_rooms[hash2], to_push2->name, to_push2->coord_x, to_push2->coord_y);
			printlst(env);
			//	else
			//		ft_rooms_push_front(&(env)->tab_rooms[hash1], to_push1->name, to_push1->coord_x, to_push1->coord_y);
			//	if (hash2 < hash1)
			//		ft_rooms_push_back(&(env)->tab_rooms[hash2], to_push2->name, to_push2->coord_x, to_push2->coord_y);
			//	else
			//		ft_rooms_push_front(&(env)->tab_rooms[hash2], to_push2->name, to_push2->coord_x, to_push2->coord_y);
			ft_rooms_sort(env->tab_rooms[hash1]);
			ft_rooms_sort(env->tab_rooms[hash2]);
			//			env->tbl_rooms[i] = ft_rooms_find(env->rooms, hash1);
			//			tmp = env->tab_rooms[hash1];
			break ;
		}
		/*		else if (i == hash2)
				{
				}*/
		else
			i++;
	}
	ft_printf("\n");
}
