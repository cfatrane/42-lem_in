/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 11:36:27 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/16 13:26:08 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "lem_in_struct.h"
# include <math.h>

int			lem_in(t_lem_in *env);

int			ft_error_nbr(char *line);
int			ft_error_rooms(char *name, char *x, char *y);

int			check_ants(t_lem_in *env);
int			check_rooms(t_lem_in *env);

void		take_start(t_lem_in *env, char *name, int coord_x, int coord_y);
void		take_end(t_lem_in *env, char *name, int coord_x, int coord_y);

int			ft_start(t_lem_in *env, char *line);
int			ft_rooms(t_lem_in *env, char *line);
int			ft_end(t_lem_in *env, char *line);
int			ft_links(t_lem_in *env, char *line);
int			ft_comment(t_lem_in *env, char *line);

int			ft_is_links(t_lem_in *env, char *line);

t_lstrooms	*collision(t_lem_in *env);
int			hachage(t_lem_in *env, char *str);
int			max_hash(t_lem_in *env);

t_lstrooms	*ft_modify_doublon(t_lstrooms *rooms);

t_lstrooms	*ft_create_elem_rooms(char *name, int x, int y);
void		ft_push_back_rooms(t_lstrooms **rooms, char *name, int x, int y);
void		ft_push_front_rooms(t_lstrooms **rooms, char *name, int x, int y);
t_lstrooms	*ft_rooms_find_hash(t_lstrooms *rooms, int content_ref);
t_lstrooms	*ft_rooms_find_name(t_lstrooms *rooms, char *name_ref);
void		ft_rooms_clear(t_lstrooms **begin_list);
t_lstrooms	*ft_rooms_sort(t_lstrooms *lst);
t_lstrooms	*ft_lstcpy(t_lstrooms *dst, t_lstrooms *src);
void		ft_push_front_tab(t_lstrooms **rooms, t_lstrooms *src, int hash);
void		ft_push_back_tab(t_lstrooms **rooms, t_lstrooms *src, int hash);

void		ft_printlst(t_lem_in *env);
void		ft_rooms_display(t_lstrooms *rooms);

int			check_doublon_hash(t_lem_in *env);
int			check_doublon_name(t_lem_in *env);
int			check_doublon_coord(t_lem_in *env);
int			check_doublon_links(t_lem_in *env, int hash1, int hash2);

#endif
