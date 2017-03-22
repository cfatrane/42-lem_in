/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:10:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/22 13:49:07 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	printint(t_int *list)
{
	t_int *tmp = list;

	while (tmp)
	{
		ft_printf("Val = %d\n", tmp->i);
		tmp = tmp->next;
	}
}

int		print_path(t_lem_in *env, int src, int dest, t_tab *tab)
{
	if (src == dest)
		ft_printf("L1-%d", src);
	else if (tab->parent[dest] == -1)
	{
		ft_printf("Il n'y a pas de chemin de %d vers %d", src, dest);
		return (-1);
	}
	else
	{
		print_path(env, src, tab->parent[dest], tab);
		ft_printf("\nL1-%d", dest);
	}
	return (0);
}

int		print_path_two(t_lem_in *env, int src, int dest, t_tab *tab)
{
	t_int	*index;

	index = NULL;
	while (src != dest)
	{
		ft_push_front_int(&index, dest);
		dest = tab->parent[dest];
	}
	if (src == dest)
		ft_printf("\nsrc first = %d\n", src);
	while (index)
	{
		ft_printf("L1-%d\n", tab->parent[index->i]);
		if (index->next == NULL)
			ft_printf("L1-%d", index->i);
		index = index->next;
	}
	return (0);
}

int		init_bfs(int src, t_lem_in *env, t_tab *tab)
{
	int	i;

	i = 0;
	if (!(tab->color = (int*)malloc(sizeof(*tab->color) * env->malloc)))
		return (-1);
	if (!(tab->dist = (int*)malloc(sizeof(*tab->dist) * env->malloc)))
		return (-1);
	if (!(tab->parent = (int*)malloc(sizeof(*tab->parent) * env->malloc)))
		return (-1);
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
	if (print_path(env, src, env->end_hash, tab) == -1)
		return (-1);
	ft_printf("\n\n\n");
	ft_printf("dst = %d\n\n", env->end_hash);
	if (print_path_two(env, src, env->end_hash, tab) == -1)
		return (-1);
	ft_printf("\n");
	return (0);
}
