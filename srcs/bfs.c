/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:10:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/19 18:24:47 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

typedef enum	e_color
{
	WHITE, GREY, BLACK
}				t_color;

int	*color;
int	*dist;
int	*parent;

void	bfs(int src, t_lem_in *env)
{
	int	i;

	i = 0;
	if (!(color = (int*)malloc(sizeof(*color) * ft_nbcmp_max(env->nb_rooms, max_hash(env)))))
		return ;
	if (!(dist = (int*)malloc(sizeof(*dist) * ft_nbcmp_max(env->nb_rooms, max_hash(env)))))
		return ;
	if (!(parent = (int*)malloc(sizeof(*parent) * ft_nbcmp_max(env->nb_rooms, max_hash(env)))))
		return ;
	while (i < env->nb_rooms)
	{
		color[i] = WHITE;
		dist[i] = INT_MAX;
		parent[i] = -1;
		i++;
	}
	color[src] = GREY;
	dist[src] = 0;
	parent[src] = -1;

	t_rooms	*queue = NULL;

	while (ft_rooms_size(queue) != 0)
	{
		int u = 2;
		t_rooms	*tmp = env->tab_rooms[u];
		while (tmp)
		{
			int v = i;
			if (color == WHITE)
			{
				dist[v] = dist[u] + 1;
				color[v] = GREY;
				parent[v] = u;

			}
			tmp = tmp->next;
			i++;
		}
		color[u] = BLACK;
	}
}
