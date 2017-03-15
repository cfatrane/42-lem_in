/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 11:36:27 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/15 11:21:15 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "lem_in_struct.h"
# include <math.h>

int		lem_in(t_lem_in *env);

int		ft_error_nbr(char *line);
int		ft_error_rooms(char *name, char *x, char *y);

int		check_ants(t_lem_in *env);
int		check_rooms(t_lem_in *env);

int		ft_start(t_lem_in *env, char *line);
int		ft_rooms(t_lem_in *env, char *line);
int		ft_end(t_lem_in *env, char *line);
int		ft_links(t_lem_in *env, char *line);
int		ft_comment(t_lem_in *env, char *line);

int		ft_is_links(t_lem_in *env, char *line);

t_rooms	*collision(t_lem_in *env);
int		hachage_lst(t_lem_in *env, char *str);
int		max_hash(t_lem_in *env);

int		ft_check_doublon(t_lem_in *env);
t_rooms	*ft_modify_doublon(t_rooms *rooms);

t_rooms	*ft_create_elem_rooms(char *name, int x, int y);
void	ft_rooms_push_back(t_rooms **rooms, char *name, int x, int y);
void	ft_rooms_push_front(t_rooms **rooms, char *name, int x, int y);
t_rooms	*ft_rooms_find_hash(t_rooms *rooms, int content_ref);
t_rooms	*ft_rooms_find_name(t_rooms *rooms, char *name_ref);
void	ft_rooms_clear(t_rooms **begin_list);
t_rooms	*ft_rooms_sort(t_rooms *lst);
t_rooms	*ft_lstcpy(t_rooms *dst, t_rooms *src);
void	ft_rooms_push_front_tab(t_rooms **rooms, t_rooms *src, int hash);
void	ft_rooms_push_back_tab(t_rooms **rooms, t_rooms *src, int hash);

void	printlst(t_lem_in *env);
void	ft_rooms_display(t_rooms *rooms);

void	bfs(int src, t_lem_in *env);

t_rooms	*decol(t_rooms *lst);

#endif
