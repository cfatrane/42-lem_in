/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:33:56 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/26 19:23:05 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_line	*ft_create_elem_line(char *data)
{
	t_line	*line;

	if (!(line = (t_line*)malloc(sizeof(*line))))
		return (NULL);
	line->line = ft_strdup(data);
	line->next = NULL;
	return (line);
}

void	ft_push_back_line(t_line **line, char *data)
{
	if (*line)
	{
		if ((*line)->next)
			ft_push_back_line(&(*line)->next, data);
		else
			(*line)->next = ft_create_elem_line(data);
	}
	else
		*line = ft_create_elem_line(data);
}

void	print_data(t_lem_in *env)
{
	t_line	*tmp;

	tmp = env->data;
	while (tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
	if (env->flag_entry != 1)
		ft_printf("\n");
}
