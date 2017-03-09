/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:57:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/08 10:42:29 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	error(void)
{
	ft_printf("ERROR\n");
	return (-1);
}

void	ft_rooms_display(t_lem_in *env)
{
	t_rooms	*tmp;

	tmp = env->rooms;
	while (tmp)
	{
		ft_printf("\033[31mName = %s Coord X = %d Coord Y = %d\n\033[0m", tmp->name, tmp->coord_x, tmp->coord_y);
		tmp = tmp->next;
	}
}

int	ft_is_links(t_lem_in *env, char *line)
{
	int	i;
	int flag = 0;

	i = 1;
	int y = 0;
	t_rooms *tmp = env->rooms;
	while (line[y] && line[y] != '-')
	{
		y++;
	}
//	ft_printf("y = %d\n", y);
	while (tmp)
	{
		//		ft_printf("line = %s\troom = %s\n", line, tmp->name);
		if (ft_strncmp(line, tmp->name, y) == 0)
		{
			flag++;
//			ft_printf("flag cmp 1 = %d\n", flag);
			if (line[y] == '-')
			{
				y++;
				flag++;
//				ft_printf("flag tiret 2 = %d\n", flag);
			}
//			ft_printf("line two = %s\n", &line[y]);
		}
		tmp = tmp->next;
	}
	tmp = env->rooms;
	while (tmp)
	{
		if (ft_strncmp(&line[y], tmp->name, ft_strlen(line) - y) == 0)
		{
			flag++;
			break ;
//			ft_printf("flag cmp 3 = %d\n", flag);
		}
		//		ft_printf("line = %s\troom = %s\n", line, tmp->name);
		tmp = tmp->next;
	}
	if (flag == 3)
		return (1);
	else
		return (0);
//	ft_printf("flag = %d\n", flag);
/*	while (line[i])
	{
		if (ft_isdigit(line[i - 1]) && line[i] == '-' && ft_isdigit(line[i + 1]))
			return (1);
		i++;
	}*/
	return (0);
}

void	ft_rooms_clear(t_rooms **begin_list)
{
	if (*begin_list != NULL)
	{
		ft_rooms_clear(&((*begin_list)->next));
		free(*begin_list);
		*begin_list = NULL;
	}
}
