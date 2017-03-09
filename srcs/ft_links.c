/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:41:38 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/09 10:40:53 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	**ant_farm(int x, int y)
{
	char	**ptr;
	int		i;

	ptr = malloc(y * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		ptr[i] = (char*)malloc(x * sizeof(**ptr));
		if (ptr[i] == NULL)
			return (NULL);
		i++;
	}
	ptr[i] = "\0";
	return (ptr);
}

int	ft_links(t_lem_in *env, char *line)
{
	int		i;
	int x;
	int y;

	x = 0;
	ft_printf("\033[31mDEBUT LINKS ROOMS ROOMS ROOMS ROOMS ROOMS ROOMS \n\033[0m");
	ft_printf("\033[32mLINKS LINE = %s\n\033[0m", line);
//	ft_printf("\033[32mLINKS LINE = %s TMP = %s\n\033[0m", line, env->line_tmp);
	if (!(env->ant_farm))
		if (!(env->ant_farm = ant_farm(env->nb_rooms, env->nb_rooms)))
			return (-1);
	i = 0;
	env->flag_path = 1;
	while (line[i] != '-')
		i++;
	i++;
	int test = hachage(env, ft_strdup_c(line, '-'));
	ft_printf("TEST = %d\n", test);
//	int one = ft_atoi(line);
//	ft_printf("NBR ONE = %d\n", one);
/*	while (ft_isdigit(line[i]))
		i++;
	i++;*/
	int test2 = hachage(env, &line[i]);
	ft_printf("TEST 2 = %d\n", test2);
/*	if (!ft_isdigit(line[i]))
	{
		ft_printf("NO DIGIT\n");
		return (-1);
	}
	int	two = ft_atoi(&line[i]);*/
//	ft_printf("NBR TWO = %d\n", two);
//	env->ant_farm[one][two] = '1';
//	env->ant_farm[two][one] = '1';
	env->ant_farm[test][test2] = '1';
	env->ant_farm[test2][test] = '1';
	while (x < env->nb_rooms)
	{
		y = 0;
		while (y < env->nb_rooms)
		{
			//		printf("C = |%c| X = |%d| et Y = |%d|", env->ant_farm[x][y], x, y);
			if (env->ant_farm[x][y] != '1')
				env->ant_farm[x][y] = '0';
			y++;
		}
		//	ft_printf("\n");
		x++;
	}
	ft_printf("\033[31mFIN LINKS ROOMS ROOMS ROOMS ROOMS ROOMS ROOMS \n\n\033[0m");
	return (0);
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
