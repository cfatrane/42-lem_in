/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:10:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 16:39:23 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	print_path(int src, int dest, t_tab *tab)
{
	if (src == dest)
		printf("%d", src);
	else if (tab->parent[dest] == -1)
	{
		printf("Il n'y a pas de chemin de %d vers %d", src, dest);
		return (-1);
	}
	else
	{
		print_path(src, tab->parent[dest], tab);
		printf(" %d", dest);
	}
	return (0);
}

void	init_bfs(int src, t_lem_in *env, t_tab *tab)
{
	int	i;

	i = 0;
	if (!(tab->color = (int*)malloc(sizeof(*tab->color) *
					ft_nbcmp_max(env->nb_rooms, max_hash(env)))))
		return ;
	if (!(tab->dist = (int*)malloc(sizeof(*tab->dist) *
					ft_nbcmp_max(env->nb_rooms, max_hash(env)))))
		return ;
	if (!(tab->parent = (int*)malloc(sizeof(*tab->parent) *
					ft_nbcmp_max(env->nb_rooms, max_hash(env)))))
		return ;
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
	if (print_path(src, env->end_hash, tab) == -1)
		return (-1);
	return (0);
}
