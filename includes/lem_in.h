/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 11:36:27 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/09 19:41:46 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "lem_in_struct.h"

int		lem_in(t_lem_in *env);

int		ft_error(char *av);
int		error(void);

int		check_ants(t_lem_in *env);
int		check_rooms(t_lem_in *env);

int		ft_start(t_lem_in *env, char *line);
int		ft_end(t_lem_in *env, char *line);
int		ft_links(t_lem_in *env, char *line);
int		ft_comment(t_lem_in *env, char *line);

int		hachage(t_lem_in *env, char *str);
int	hachage_lst(char *str);

t_rooms	*ft_create_elem_rooms(char *name, int coord_x, int coord_y);
void	ft_rooms_push_back(t_rooms **rooms, char *name, int coord_x, int coord_y);
void	ft_rooms_push_front(t_rooms **stack, char *name, int coord_x, int coord_y);

t_rooms	*ft_rooms_sort(t_rooms *lst);
void	printlst(t_lem_in *env);

int	ft_is_links(t_lem_in *env, char *line);

int	ft_rooms(t_lem_in *env, char *line);

void	ft_rooms_clear(t_rooms **begin_list);
int		parcours_hash(t_lem_in *env);

t_rooms	*ft_rooms_find(t_rooms *begin_list, int content_ref);

int	error_rooms(t_lem_in *env);

void	put_in_tab(t_lem_in *env, int hash1, int hash2);

void	ft_rooms_display(t_lem_in *env);

#endif
