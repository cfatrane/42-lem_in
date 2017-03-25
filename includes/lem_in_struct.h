/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:24:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/25 15:21:11 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

# include "lem_in.h"

typedef enum			e_color
{
	WHITE,
	GREY,
	BLACK
}						t_color;

typedef struct			s_line
{
	char				*line;
	struct s_line		*next;
}						t_line;

typedef struct			s_tab
{
	int					*color;
	int					*dist;
	int					*parent;
}						t_tab;

typedef struct			s_path
{
	char				*name;
	int					ants;
	int					data;
	struct s_path		*next;
}						t_path;

typedef struct			s_rooms
{
	char				*name;
	int					coord_x;
	int					coord_y;
	int					hash;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_lem_in
{
	int					ants;
	int					nb_rooms;
	int					nb_links;
	int					nb_vertices;
	int					flag_start;
	int					flag_end;
	int					flag_rooms;
	int					flag_path;
	int					flag_links;
	int					flag_dbl;
	int					flag_print;
	int					flag_entry;
	int					start_hash;
	int					end_hash;
	int					malloc;
	char				*start_name;
	char				*end_name;
	struct s_line		*data;
	struct s_path		*path;
	struct s_rooms		*rooms;
	struct s_rooms		**tab_rooms;
}						t_lem_in;

#endif
