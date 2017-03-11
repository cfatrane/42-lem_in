/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:41:38 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 17:03:33 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


int	ft_links(t_lem_in *env, char *line)
{
	int	i;
	int	x;

	x = 0;
	//	ft_printf("\033[31mDEBUT LINKS ROOMS ROOMS ROOMS ROOMS ROOMS ROOMS \n\033[0m");
	//	ft_printf("\033[32mLINKS LINE = %s\n\033[0m", line);
	//	ft_printf("\033[32mLINKS LINE = %s TMP = %s\n\033[0m", line, env->line_tmp);
	/*	if (!(env->ant_farm))
	//	if (!(env->ant_farm = ant_farm(env->nb_rooms, env->nb_rooms)))
	if (!(env->ant_farm = ant_farm(10000, 10000))) // ENLEVER TABLEAU STRUCT ET LA
	return (-1);*/
	int max = max_hash(env);
	if (!(env->tab_rooms))
	{
		if (!(env->tab_rooms = ft_memalloc(sizeof(t_rooms**) * max + 1)))
			return (-1);
	}
	i = 0;
	env->flag_path = 1;
	while (line[i] != '-')
		i++;
	i++;
	int test1 = hachage_lst(ft_strdup_c(line, '-'));
	int test2 = hachage_lst(&line[i]);
	t_rooms	*to_push2 = ft_rooms_find(env->rooms, test1);
	t_rooms	*to_push1 = ft_rooms_find(env->rooms, test2);
	ft_rooms_push_back(&(env)->tab_rooms[test1], to_push1->name, to_push1->coord_x, to_push1->coord_y);
	ft_rooms_sort(env->tab_rooms[test1]);
	ft_rooms_push_back(&(env)->tab_rooms[test2], to_push2->name, to_push2->coord_x, to_push2->coord_y);
	ft_rooms_sort(env->tab_rooms[test2]);
	return (0);
}
int	ft_is_links(t_lem_in *env, char *line)
{
	int	i;
	int flag = 0;

	i = 1;
	int y = 0;
	t_rooms *tmp = env->rooms;
	while (line[y] && line[y] != '-')
	{
		y++;
	}
	//	ft_printf("y = %d\n", y);
	while (tmp)
	{
		//		ft_printf("line = %s\troom = %s\n", line, tmp->name);
		if (ft_strncmp(line, tmp->name, y) == 0)
		{
			flag++;
			//			ft_printf("flag cmp 1 = %d\n", flag);
			if (line[y] == '-')
			{
				y++;
				flag++;
				//				ft_printf("flag tiret 2 = %d\n", flag);
			}
			//			ft_printf("line two = %s\n", &line[y]);
		}
		tmp = tmp->next;
	}
	tmp = env->rooms;
	while (tmp)
	{
		if (ft_strncmp(&line[y], tmp->name, ft_strlen(line) - y) == 0)
		{
			flag++;
			break ;
			//			ft_printf("flag cmp 3 = %d\n", flag);
		}
		//		ft_printf("line = %s\troom = %s\n", line, tmp->name);
		tmp = tmp->next;
	}
	if (flag == 3)
		return (1);
	return (0);
}

void	ft_rooms_clear(t_rooms **begin_list)
{
	if (*begin_list != NULL)
	{
		ft_rooms_clear(&((*begin_list)->next));
		free(*begin_list);
		*begin_list = NULL;
	}
}
