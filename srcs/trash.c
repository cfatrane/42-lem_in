/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:48:28 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/14 12:40:29 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_rooms	**ft_tab_rooms(int x, int y)
{
	t_rooms	**ptr;
	int		i;

	ptr = (t_rooms**)malloc(y * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		ptr[i] = (t_rooms*)malloc(x * sizeof(ptr));
		if (ptr[i] == NULL)
			return (NULL);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

int		ft_links(t_lem_in *env, char *line)
{
	int		hash1;
	int		hash2;
	int		max;
	t_rooms	*tmp;

	//	ft_printf("IN LINKS DEBUG 1\n");
	//	env->rooms = ft_lstcpy(env->rooms, collision(env));
	ft_lstcpy(env->rooms, collision(env));
	//	ft_printf("IN LINKS DEBUG 2\n");
	max = max_hash(env) + 1;
	//	ft_printf("MAX = %d\n", max);
	if (!(env->tab_rooms))
		if (!(env->tab_rooms = ft_memalloc(sizeof(t_rooms**) * max)))
			return (-1);
/*	if (!(env->tab_rooms))
		if (!(env->tab_rooms = ft_tab_rooms(max, max)))
			return (-1);
*/
	env->flag_path = 1;
	tmp = ft_rooms_find_name(env->rooms, ft_strdup_c(line, '-'));
	hash1 = tmp->hash;
	tmp = ft_rooms_find_name(env->rooms, ft_strchr(line, '-') + 1);
	hash2 = tmp->hash;
	tmp = ft_rooms_find_hash(env->rooms, hash2);
	//	ft_printf("ISSOU\n");
	ft_rooms_push_back_tab(&(env)->tab_rooms[hash1], tmp, hash2);
		return (-1);
	//	ft_printf("CHANCLA\n");
	ft_rooms_sort(env->tab_rooms[hash1]);
	tmp = ft_rooms_find_hash(env->rooms, hash1);
	//	ft_printf("IN LINKS DEBUG FIN\n");
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

-------------------------------------------------------------------
	for(int i = 1; i <= N; ++i)
	{
		color[i] = WHITE; // On colorie tous les noeuds en blanc
		dist[i] = INF; // On affecte INF à la distance de chaque noeud
		parent[i] = NIL; // On affecte NIL au parent de chaque noeud
	}


int		ft_modify(t_lem_in *env)
{
	int		hash_tmp;
	int		flag = 0;
//	int		i = 0;
	t_rooms	*tmp_1;
	t_rooms	*tmp_2;
	t_rooms	*tmp_3;
	t_rooms	*tmp;

	tmp_1 = env->rooms;
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		hash_tmp = tmp_1->hash;
		while (tmp_2)
		{
			if (hash_tmp == tmp_2->hash)
			{
				ft_printf("|Name = %s Hash = %d| avec |Name = %s Hash = %d|\n", tmp_1->name, tmp_1->hash, tmp_2->name, tmp_2->hash);
			//	ft_printf("|Name = %s Hash = %d| avec |Name = %s Hash = %d| COLLISION\n", tmp_1->name, tmp_1->hash, tmp_2->name, tmp_2->hash);
				while (1)
				{
//					tmp_2 = env->rooms;
//					hash_tmp = tmp_2->hash;
					while (tmp_2)
					{
						tmp_2->hash++;
						hash_tmp = tmp_2->hash;
						tmp_3 = tmp_2->next;
						while (tmp_3)
						{
//							ft_printf("LA tmp3 hash = %d\n", tmp_3->hash);
							if (hash_tmp == tmp_3->hash)
								break ;
							if (tmp_3->next == NULL)
								flag = 1;
							tmp_3 = tmp_3->next;
						}
						ft_printf("name = %s hash = %d\n", tmp_2->name, tmp_2->hash);
//						ft_printf("FIN\n");
					/*	if (tmp_2->hash )
						{
						}*/
						if (flag == 1)
							tmp_2 = tmp_2->next;
						tmp = tmp_2;
						while (tmp)
						{
//							ft_printf("ISSOU\n");
							tmp = tmp->next;
						}
					}
					break ;
				}
//				return (-1);
			}
			ft_printf("AFTER BREAK\n");
			if (tmp_2->next == NULL)
				break ;
			ft_printf("AFTER BREAK 2\n");
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (0);
}
