/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:10:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/28 13:21:26 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

size_t	ft_path_size(t_path *path)
{
	if (path == NULL)
		return (0);
	return (ft_path_size(path->next) + 1);
}

int		check_path(t_lem_in *env, int src, int dest, t_tab *tab)
{
	if (src == dest)
		ft_push_front_path(&env->path, dest, 0, ft_get_name(env->rooms, dest));
	else if (tab->parent[dest] == -1)
		return (-1);
	else
	{
		ft_push_front_path(&env->path, dest, 0, ft_get_name(env->rooms, dest));
		check_path(env, src, tab->parent[dest], tab);
	}
	return (0);
}

int		init_bfs(int src, t_lem_in *env, t_tab *tab)
{
	int	i;

	if (!(tab->color = ft_tabnew(env->malloc)))
		return (-1);
	if (!(tab->dist = ft_tabnew(env->malloc)))
		return (-1);
	if (!(tab->parent = ft_tabnew(env->malloc)))
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

void	bfs_fill(t_tab *tab, t_path **queue, int u, int v)
{
	if (tab->color[v] == WHITE)
	{
		tab->dist[v] = tab->dist[u] + 1;
		tab->color[v] = GREY;
		tab->parent[v] = u;
		ft_push_back_path(queue, v, 0, NULL);
	}
}

int		bfs(int src, t_lem_in *env, t_tab *tab)
{
	int		u;
	int		v;
	t_path	*queue;
	t_rooms	*tmp;

	queue = NULL;
	init_bfs(src, env, tab);
	ft_push_back_path(&queue, src, 0, NULL);
	while (ft_path_size(queue) != 0)
	{
		u = ft_path_first(queue);
		ft_path_delone_front(&queue);
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
	move_ants(env);
	return (0);
}
