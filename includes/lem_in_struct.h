/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:24:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/02 11:25:14 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

# include "lem_in.h"

typedef struct	s_rooms
{
	char		*name;
	int			coord_x;
	int			coord_y;
}				t_rooms;

typedef struct	s_links
{
}				t_links;

typedef struct	s_lem_in
{
	int			ants;
	t_rooms		rooms;
	t_links		links;
}				t_lem_in;

#endif