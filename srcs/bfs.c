/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:10:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/22 15:22:29 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_path(t_lem_in *env, int src, int dest, t_tab *tab)
{
	if (src == dest)
	{
		ft_push_front_int(&env->elem, dest);
		ft_printf("%d", src);
	}
	else if (tab->parent[dest] == -1)
	{
		ft_printf("Il n'y a pas de chemin de %d vers %d\n", src, dest);
		return (-1);
	}
	else
	{
		ft_push_front_int(&env->elem, dest);
		check_path(env, src, tab->parent[dest], tab);
		ft_printf(" %d", dest);
	}
	return (0);
}

void	print_path(t_lem_in *env)
{
	t_int	*tmp;

	tmp = env->elem->next;
	ft_printf("\n");
	while (tmp)
	{
		ft_printf("L1-%s\n", ft_get_name(env->rooms, tmp->data));
		tmp = tmp->next;
	}
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
