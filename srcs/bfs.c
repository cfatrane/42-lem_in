/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:10:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 14:23:46 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	printtmp(t_int *queue);

typedef enum	e_color
{
	WHITE, GREY, BLACK
}				t_color;


int	*color;
int	*dist;
int	*parent;

void print_path(int src, int dest)
{
	if(src == dest)
		printf("%d", src);
	else if(parent[dest] == -1)
		printf("Il n'y a pas de chemin de %d vers %d", src, dest);
	else
	{
		print_path(src, parent[dest]);
		printf(" %d", dest);
	}
}

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

	t_int	*queue = NULL;
	ft_push_back_int(&queue, src);
	while (ft_int_size(queue) != 0)
	{
		int u = ft_int_first(queue);
		ft_int_delone_front(&queue);
		ft_printf("|U = %d|\n", u);
		t_rooms	*tmp = env->tab_rooms[u];
		while (tmp)
		{
			int v = tmp->hash;
			ft_printf("v = %d\n", v);
			if (color[v] == WHITE)
			{
				dist[v] = dist[u] + 1;
				color[v] = GREY;
				parent[v] = u;
				ft_push_back_int(&queue, v);
			}
			tmp = tmp->next;
		}
		color[u] = BLACK;
	}

	/* Il ne nous reste plus qu'à afficher le chemin menant à chaque noeud */
	for(int i = 0; i <= env->nb_rooms - 1; ++i)
	{
		printf("Chemin de %d vers %d : ", src, i);
		print_path(src, i);
		printf("\n");
	}
}

void	printtmp(t_int *queue)
{
	t_int *tmp = queue;
	while (tmp)
	{
		ft_printf("I == %d\n", tmp->i);
		tmp = tmp->next;
	}
}
