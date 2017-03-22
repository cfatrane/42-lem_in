/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:10:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/22 18:26:00 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_path(t_lem_in *env, int src, int dest, t_tab *tab)
{
	if (src == dest)
		ft_push_front_int(&env->elem, dest);
	else if (tab->parent[dest] == -1)
	{
		ft_printf("FIN");
		return (-1);
	}
	else
	{
		ft_push_front_int(&env->elem, dest);
		check_path(env, src, tab->parent[dest], tab);
	}
	return (0);
}

int		init_bfs(int src, t_lem_in *env, t_tab *tab)
{
	int	i;

	if (!(tab->color = (int*)malloc(sizeof(*tab->color) * env->malloc)))
		return (-1);
	if (!(tab->dist = (int*)malloc(sizeof(*tab->dist) * env->malloc)))
		return (-1);
	if (!(tab->parent = (int*)malloc(sizeof(*tab->parent) * env->malloc)))
		return (-1);
	i = 0;
	while (i < env->nb_rooms)
	{
		tab->color[i] = WHITE;
		tab->dist[i] = INT_MAX;
		tab->parent[i] = -1;
		i++;
	}
	tab->color[src] = GREY;
	tab->dist[src] = 0;
	tab->parent[src] = -1;
	return (0);
}

void	bfs_fill(t_tab *tab, t_int **queue, int u, int v)
{
	if (tab->color[v] == WHITE)
	{
		tab->dist[v] = tab->dist[u] + 1;
		tab->color[v] = GREY;
		tab->parent[v] = u;
		ft_push_back_int(queue, v);
	}
}

int		bfs(int src, t_lem_in *env, t_tab *tab)
{
	int		u;
	int		v;
	t_int	*queue;
	t_rooms	*tmp;

	queue = NULL;
	init_bfs(src, env, tab);
	ft_push_back_int(&queue, src);
	while (ft_int_size(queue) != 0)
	{
		u = ft_int_first(queue);
		ft_int_delone_front(&queue);
		tmp = env->tab_rooms[u];
		while (tmp)
		{
			v = tmp->hash;
			bfs_fill(tab, &queue, u, v);
			tmp = tmp->next;
		}
		tab->color[u] = BLACK;
	}
	if (check_path(env, src, env->end_hash, tab) == -1)
		return (-1);
	print_path(env);
	return (0);
}
