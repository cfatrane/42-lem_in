/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:33:04 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/23 18:34:05 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	put_in_tab(t_lem_in *env, int hash1, int hash2)
{
	t_rooms	*tmp;

	if (check_doublon_links(env, hash1, hash2) == -1)
		return ;
	tmp = ft_rooms_find_hash(env->rooms, hash2);
	ft_push_back_tab(&(env)->tab_rooms[hash1], tmp, hash2);
	ft_rooms_sort(env->tab_rooms[hash1]);
	tmp = ft_rooms_find_hash(env->rooms, hash1);
	ft_push_back_tab(&(env)->tab_rooms[hash2], tmp, hash1);
	ft_rooms_sort(env->tab_rooms[hash2]);
	env->nb_links++;
}

int		ft_links(t_lem_in *env, char *line)
{
	char	*line_tmp;
	int		hash1;
	int		hash2;
	t_rooms	*tmp;

	if (env->flag_start != 1 || env->flag_end != 1)
		return (-1);
	delete_collision(env);
	if (!(env->tab_rooms))
		if (!(env->tab_rooms = ft_memalloc(sizeof(t_rooms**) * env->malloc)))
			return (-1);
	env->flag_path = 1;
	line_tmp = ft_strdup_c(line, '-');
	tmp = ft_rooms_find_name(env->rooms, line_tmp);
	free(line_tmp);
	hash1 = tmp->hash;
	tmp = ft_rooms_find_name(env->rooms, ft_strchr(line, '-') + 1);
	hash2 = tmp->hash;
	put_in_tab(env, hash1, hash2);
	return (0);
}

void	flag_one(t_lem_in *env, char *line, int *i)
{
	t_rooms	*tmp;

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
	t_rooms	*tmp;

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
