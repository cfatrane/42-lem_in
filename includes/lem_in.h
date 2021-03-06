/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 11:36:27 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/28 18:50:36 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "lem_in_struct.h"

int		lem_in(t_lem_in *env, t_tab *tab);
int		bfs(int src, t_lem_in *env, t_tab *tab);

int		ft_error_nbr(char *line);
int		ft_error_rooms(char *name, char *x, char *y);

int		check_ants(t_lem_in *env);
int		check_rooms(t_lem_in *env, t_tab *tab);

int		ft_start(t_lem_in *env, char *line);
int		ft_rooms(t_lem_in *env, char *line);
int		ft_end(t_lem_in *env, char *line);
int		ft_is_links(t_lem_in *env, char *line);
int		ft_links(t_lem_in *env, char *line);
int		ft_comment(t_lem_in *env, char *line);

t_rooms	*collision(t_lem_in *env);
int		hachage(t_lem_in *env, char *str);
int		max_hash(t_lem_in *env);
t_rooms	*ft_modify_doublon(t_rooms *rooms);

t_rooms	*ft_rooms_find_hash(t_rooms *rooms, int content_ref);
t_rooms	*ft_rooms_find_name(t_rooms *rooms, char *name_ref);
int		ft_get_hash(t_rooms *rooms, char *name_ref);
char	*ft_get_name(t_rooms *rooms, int hash_ref);

void	ft_rooms_clear(t_rooms **rooms);
t_rooms	*ft_rooms_sort(t_rooms *lst);
t_rooms	*ft_lstcpy(t_rooms *dst, t_rooms *src);

int		check_doublon_hash(t_lem_in *env);
int		check_doublon_name(t_lem_in *env);
int		check_doublon_coord(t_lem_in *env);
int		check_doublon_links(t_lem_in *env, int hash1, int hash2);
void	delete_collision(t_lem_in *env);

size_t	ft_rooms_size(t_rooms *stack);
size_t	ft_path_size(t_path *path);

t_rooms	*ft_create_elem_rooms(char *name, int x, int y);
void	ft_push_back_rooms(t_rooms **rooms, char *name, int x, int y);
void	ft_push_front_rooms(t_rooms **rooms, char *name, int x, int y);

void	ft_push_front_tab(t_rooms **rooms, t_rooms *src, int hash);
void	ft_push_back_tab(t_rooms **rooms, t_rooms *src, int hash);

void	ft_push_back_path(t_path **path, int data, int ants, char *name);
void	ft_push_front_path(t_path **path, int data, int ants, char *name);
void	ft_path_delone_back(t_path *path);
void	ft_path_delone_front(t_path **path);
int		ft_path_first(t_path *path);
size_t	ft_path_size(t_path *path);

void	ft_push_back_line(t_line **line, char *data);
void	print_data(t_lem_in *env);

void	move_ants(t_lem_in *env);

void	ft_printlst(t_lem_in *env);
void	ft_rooms_display(t_rooms *rooms);
void	ft_print_shortest_path(t_lem_in *env);
void	ft_print_full_path(t_lem_in *env, t_tab *tab);
int		active_flag(t_lem_in *env, int argc, char **argv);
void	ft_rooms_display_name(t_rooms *rooms);

void	free_env(t_lem_in *env, t_tab *tab);

#endif
