/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:41:38 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/12 13:25:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_links(t_lem_in *env, char *line)
{
	int		hash1;
	int		hash2;
	int		max;
	t_rooms	*to_push;

	max = max_hash(env) + 1;
	if (!(env->tab_rooms))
		if (!(env->tab_rooms = ft_memalloc(sizeof(t_rooms**) * max)))
			return (-1);
	env->flag_path = 1;
	hash1 = hachage_lst(ft_strdup_c(line, '-'));
	hash2 = hachage_lst(ft_strchr(line, '-') + 1);
	to_push = ft_rooms_find(env->rooms, hash2);
	ft_rooms_push_back(&(env)->tab_rooms[hash1], to_push->name,
			to_push->coord_x, to_push->coord_y);
	to_push = ft_rooms_find(env->rooms, hash1);
	ft_rooms_sort(env->tab_rooms[hash1]);
	ft_rooms_push_back(&(env)->tab_rooms[hash2], to_push->name,
			to_push->coord_x, to_push->coord_y);
	ft_rooms_sort(env->tab_rooms[hash2]);
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
		i++;
	if (line[i] == '\0')
		return (0);
	flag_one(env, line, &i);
	flag_two(env, line, i);
	if (env->flag_links == 3)
		return (1);
	return (0);
}
