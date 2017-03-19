/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:42:22 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/19 16:48:04 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

const int INF = 2147483647;
const int NIL = -1;
const int N = 6;
const int MAX = N + 1;

enum {WHITE, GREY, BLACK};

//vector<int> color(MAX);
//vector<int> dist(MAX);
//vector<int> parent(MAX);

/* Parcours en largeur */
void bfs(int src, list<int> graph[])
{
	int color[MAX];
	int dist[MAX];
	int parent[MAX];

	for(int i = 1; i <= N; ++i)
	{
		color[i] = WHITE;
		dist[i] = INF;
		parent[i] = NIL;
	}

	color[src] = GREY;
	dist[src] = 0;
	parent[src] = NIL;

	queue<int> q;
	q.push(src);

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(list<int>::iterator it = graph[u].begin(); it != graph[u].end(); ++it)
		{
			int v = *it;
			if(color[v] == WHITE)
			{
				color[v] = GREY;
				dist[v] = dist[u] + 1;
				parent[v] = u;

				q.push(v);
			}
		}

		color[u] = BLACK;
	}
}

/* Affiche le chemin menant de src à dest */
void print_path(int src, int dest)
{
	if(src == dest)
		printf("%d", src);
	else if(parent[dest] == NIL)
		printf("Il n'y a pas de chemin de %d vers %d", src, dest);
	else
	{
		print_path(src, parent[dest]);
		printf(" %d", dest);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	list<int> graph[MAX];

	while(n--)
	{
		int u = 0, v = 0;
		scanf("%d %d", &u, &v);

		/* Puisque c'est un graphe non orienté, il faut indiquer que ... */
		graph[u].push_front(v); // u est connecté à v ...
		graph[v].push_front(u); // et que v aussi est connecté à u

	}

	int src = 1;
	bfs(src, graph); // On fait le parcours en largeur

	/* Il ne nous reste plus qu'à afficher le chemin menant à chaque noeud */
	for(int i = 2; i <= N; ++i)
	{
		printf("Chemin de %d vers %d : ", src, i);
		print_path(src, i);
		printf("\n");
	}

	return 0;
}
