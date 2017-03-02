/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 11:35:56 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/01 14:16:36 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	t_lem_in	*env;

	if (!(env = ft_memalloc(sizeof(t_lem_in))))
		return (-1);
	lem_in(env);
	return (0);
}
