/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 11:36:27 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 18:41:51 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "lem_in_struct.h"

int		lem_in(t_lem_in *env);

int		ft_error_nbr(char *line);
int		ft_error_rooms(char *name, char *x, char *y);
int		ft_check_format_name(char *str);

int		check_ants(t_lem_in *env);
int		check_rooms(t_lem_in *env);

int		ft_start(t_lem_in *env, char *line);
int		ft_rooms(t_lem_in *env, char *line);
int		ft_end(t_lem_in *env, char *line);
int		ft_links(t_lem_in *env, char *line);
int		ft_comment(t_lem_in *env, char *line);

int		hachage_lst(char *str);
int		max_hash(t_lem_in *env);

int		ft_is_links(t_lem_in *env, char *line);

t_rooms	*ft_create_elem_rooms(char *name, int x, int y);
void	ft_rooms_push_back(t_rooms **rooms, char *name, int x, int y);
t_rooms	*ft_rooms_find(t_rooms *begin_list, int content_ref);
void	ft_rooms_clear(t_rooms **begin_list);

t_rooms	*ft_rooms_sort(t_rooms *lst);
void	printlst(t_lem_in *env);
void	ft_rooms_display(t_lem_in *env);

int		parcours_hash(t_lem_in *env);

int		error_rooms(t_lem_in *env);


#endif
