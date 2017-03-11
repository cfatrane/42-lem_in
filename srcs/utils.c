/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:57:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/11 13:52:12 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	error(void)
{
	ft_printf("ERROR\n");
	return (-1);
}

int	tab_len(t_lem_in *env)
{
	int len;

	len = 0;
	(void)env;

	return (len);
}
t_rooms	*ft_rooms_find(t_rooms *rooms, int hash_ref)
{
	if (rooms == NULL)
		return (NULL);
	if (ft_nbrcmp(rooms->hash, hash_ref) == 0)
		return (rooms);
	else if (rooms->next)
		return (ft_rooms_find(rooms->next, hash_ref));
	else
		return (NULL);
}

void	ft_swap_int(int *a, int *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
}

void	ft_swap_str(char **a, char **b)
{
	char	*i;

	i = *a;
	*a = *b;
	*b = i;
}

t_rooms	*ft_rooms_sort(t_rooms *lst)
{
//	int		tempo;
	t_rooms	*parcour;

	parcour = lst;
	while (lst->next)
	{
		if (lst->hash > lst->next->hash)
		{
			ft_swap_str(&lst->name, &lst->next->name);
			ft_swap_int(&lst->coord_x, &lst->next->coord_x);
			ft_swap_int(&lst->coord_y, &lst->next->coord_y);
			ft_swap_int(&lst->hash, &lst->next->hash);
/*			tempo = lst->hash;
			lst->hash = lst->next->hash;
			lst->next->hash = tempo;
			lst = parcour;*/
		}
		else
			lst = lst->next;
	}
	lst = parcour;
	return (lst);
}

