/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:24:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/20 15:41:51 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

# include "lem_in.h"

typedef enum	e_color
{
	WHITE,
	GREY,
	BLACK
}				t_color;

typedef struct			s_tab
{
	int					*color;
	int					*dist;
	int					*parent;
}						t_tab;

typedef struct			s_int
{
	int					i;
	struct s_int		*next;
}						t_int;

typedef struct			s_rooms
{
	char				*name;
	int					coord_x;
	int					coord_y;
	int					hash;
	int					weight;
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
	struct s_rooms		start;
	struct s_rooms		end;
	struct s_rooms		*rooms;
	struct s_rooms		**tab_rooms;
}						t_lem_in;

#endif
