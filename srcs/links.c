/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:33:04 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/15 11:45:24 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	**ft_tab_rooms(int x, int y)
{
	t_rooms	**tab;
	int		i;

	ft_printf("LA\n");
	if (!(tab = (t_rooms**)malloc(sizeof(**tab) * (y + 1))))
		return (NULL);
	i = 0;
	while (i < y)
	{
		tab[i] = (t_rooms*)malloc(sizeof(*tab) * (x + 1));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int		ft_links(t_lem_in *env, char *line)
{
	int		hash1;
	int		hash2;
	int		max;
	t_rooms	*tmp;
	//	ft_printf("IN LINKS DEBUG 1\n");

	if (!env->flag_dbl)
	{
		ft_lstcpy(env->rooms, collision(env));
		while (ft_check_doublon(env) != 0)
			ft_modify_doublon(env->rooms);
	}
	env->flag_dbl = 1;
	//	ft_printf("IN LINKS DEBUG 2\n");
	max = max_hash(env) + 1;
	//	ft_printf("MAX = %d\n", max);
	if (!(env->tab_rooms))
		if (!(env->tab_rooms = ft_memalloc(sizeof(t_rooms**) * ft_nbcmp_max(max, env->nb_rooms))))
			return (-1);
	/*	if (!(env->tab_rooms))
		if (!(env->tab_rooms = ft_tab_rooms(max, max)))
		return (-1);*/
	env->flag_path = 1;
	tmp = ft_rooms_find_name(env->rooms, ft_strdup_c(line, '-'));
	hash1 = tmp->hash;
	tmp = ft_rooms_find_name(env->rooms, ft_strchr(line, '-') + 1);
	hash2 = tmp->hash;
	tmp = ft_rooms_find_hash(env->rooms, hash2);
	ft_rooms_push_back_tab(&(env)->tab_rooms[hash1], tmp, hash2);
	tmp = ft_rooms_find_hash(env->rooms, hash1);
	//	ft_printf("IN LINKS DEBUG FIN\n");
	ft_rooms_sort(env->tab_rooms[hash1]);
	ft_rooms_push_back_tab(&(env)->tab_rooms[hash2], tmp, hash1);
	ft_rooms_sort(env->tab_rooms[hash2]);
	//	ft_rooms_display(env->tab_rooms[hash1]);
	//	ft_rooms_display(env->tab_rooms[hash2]);
	//	ft_printf("IN LINKS DEBUG 3\n");
	return (0);
}

void	flag_one(t_lem_in *env, char *line, int *i)
{
	t_rooms *tmp;

	tmp = env->rooms;
	while (tmp)
	{
		if (ft_strncmp(line, tmp->name, *i) == 0)
		{
			env->flag_links++;
			if (line[*i] == '-')
			{
				(*i)++;
				env->flag_links++;
				break ;
			}
		}
		tmp = tmp->next;
	}
}

void	flag_two(t_lem_in *env, char *line, int i)
{
	t_rooms *tmp;

	tmp = env->rooms;
	while (tmp)
	{
		if (ft_strncmp(&line[i], tmp->name, ft_strlen(line) - i) == 0)
		{
			env->flag_links++;
			break ;
		}
		tmp = tmp->next;
	}
}

int		ft_is_links(t_lem_in *env, char *line)
{
	int		i;

	i = 0;
	env->flag_links = 0;
	while (line[i] && line[i] != '-')
	{
		if (line[i] == '\0')
			return (0);
		i++;
	}
	flag_one(env, line, &i);
	flag_two(env, line, i);
	if (env->flag_links == 3)
		return (1);
	return (0);
}
