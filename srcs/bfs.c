/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:12:15 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/13 16:31:51 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

const int INF = 2147483647; // Notre valeur "infini"
const int NIL = -1; // On choisit -1 comme valeur pour NIL
const int N = 60;
const int MAX = N + 1;

enum {WHITE, GREY, BLACK}; // Une énumération pour les couleurs BLANC, GRIS et NOIR

void	bfs(int src, t_lem_in *env)
{
	/* Pour commencer */
	int	color[MAX], dist[MAX], parent[MAX];

	for(int i = 1; i <= N; ++i)
	{
		color[i] = WHITE; // On colorie tous les noeuds en blanc
		dist[i] = INF; // On affecte INF à la distance de chaque noeud
		parent[i] = NIL; // On affecte NIL au parent de chaque noeud
	}

	color[src] = GREY; // On colorie la source en gris, on vient de le découvrir
	dist[src] = 0; // Puisque c'est le 1er noeud découvert, sa distance vaut 0
	parent[src] = NIL; // La source n'a pas de parent

	//	queue<int> q;
	//	q.push(src); // On y insère notre source

	t_rooms	*queue;
	ft_rooms_push_front(&queue, env->tab_rooms[src]->name, env->tab_rooms[src]->coord_x, env->tab_rooms[src]->coord_y);
	while (queue)
	{
		//		int u = q.front(); // on récupère le noeud en tête de la queue
		int u = queue->hash; // on récupère le noeud en tête de la queue
		//		q.pop(); // On défile la queue

		/* On parcourt la liste d'adjacence de u */
		int i = 0;
		while (env->tab_rooms[u])
		{
			ft_printf("LA\n");
			int v = i;

			if (color[v] == WHITE) // Si c'est la première fois qu'on découvre v
			{
				dist[v] = dist[u] + 1; // On calcule sa distance
				color[v] = GREY; // On le marque comme déjà découvert
				parent[v] = u; // On affecte à son parent u

				ft_rooms_push_front(&queue, env->tab_rooms[v]->name, env->tab_rooms[v]->coord_x, env->tab_rooms[v]->coord_y);
			}
			i++;
			env->tab_rooms[u] = env->tab_rooms[u]->next;
		}

	/*	for(list<int>::iterator it = graph[u].begin(); it != graph[u].end(); ++it)
		{
			int v = *it; // Simple convénience, on va utiliser v au lieu de *it

			if(color[v] == WHITE) // Si c'est la première fois qu'on découvre v
			{
				dist[v] = dist[u] + 1; // On calcule sa distance
				color[v] = GREY; // On le marque comme déjà découvert
				parent[v] = u; // On affecte à son parent u

//				q.push(v); // On insère v à la tête de la file
			}
		}*/
		queue = queue->next;
		color[u] = BLACK;
	}
}
