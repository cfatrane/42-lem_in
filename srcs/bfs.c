/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:12:15 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/13 15:16:40 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


const int INF = 2147483647; // Notre valeur "infini"
const int NIL = -1; // On choisit -1 comme valeur pour NIL
const int N = 10;
const int MAX = N + 1;

enum {WHITE, GREY, BLACK}; // Une énumération pour les couleurs BLANC, GRIS et NOIR

void bfs(int src, t_rooms **tab_rooms)
{
	/* Pour commencer */
	for(int i = 1; i <= N; ++i)
	{
		tab_rooms[i]->color = WHITE; // On colorie tous les noeuds en blanc
		tab_rooms[i]->dist = INF; // On affecte INF à la distance de chaque noeud
		tab_rooms[i]->parent = NIL; // On affecte NIL au parent de chaque noeud
	}

	tab_rooms[src]->color = GREY; // On colorie la source en gris, on vient de le découvrir
	tab_rooms[src]->dist = 0; // Puisque c'est le 1er noeud découvert, sa distance vaut 0
	tab_rooms[src]->parent = NIL; // La source n'a pas de parent

	queue<int> q;
	q.push(src); // On y insère notre source

	while(!q.empty())
	{
		int u = q.front(); // on récupère le noeud en tête de la queue
		q.pop(); // On défile la queue

		/* On parcourt la liste d'adjacence de u */
		for(list<int>::iterator it = graph[u].begin(); it != graph[u].end(); ++it)
		{
			int v = *it; // Simple convénience, on va utiliser v au lieu de *it

			if(color[v] == WHITE) // Si c'est la première fois qu'on découvre v
			{
				dist[v] = dist[u] + 1; // On calcule sa distance
				color[v] = GREY; // On le marque comme déjà découvert
				parent[v] = u; // On affecte à son parent u

				q.push(v); // On insère v à la tête de la file
			}
		}

		color[u] = BLACK;
	}
}

