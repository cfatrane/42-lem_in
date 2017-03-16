/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:24:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/16 10:37:40 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

# include "lem_in.h"

typedef struct			s_rooms
{
	char				*name;
	int					coord_x;
	int					coord_y;
	int					hash;
}						t_rooms;

typedef struct			s_lstrooms
{
	char				*name;
	int					coord_x;
	int					coord_y;
	int					hash;
	struct s_lstrooms	*next;
}						t_lstrooms;

typedef struct			s_lem_in
{
	int					ants;
	int					nb_rooms;
	int					flag_start;
	int					flag_end;
	int					flag_rooms;
	int					flag_path;
	int					flag_links;
	int					flag_dbl;
	struct s_rooms		start;
	struct s_rooms		end;
	struct s_lstrooms	*rooms;
	struct s_lstrooms	**tab_rooms;
}						t_lem_in;

#endif
