/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:55:37 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/02 15:40:46 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_format(char *line)
{
	while (*line)
	{
		if (*line == '-' || *line == '+')
			line++;
		if (!ft_isdigit(*line))
		{
			ft_printf("ERROR FORMAT\n");
			return (-1);
		}
		line++;
	}
	return (0);
}

int		ft_check_max(ssize_t line)
{
	if (line > INT_MAX)
	{
			ft_printf("ERROR OVERFLOW\n");
		return (-1);
	}
	return (0);
}

int		ft_error(char *line)
{
	if (ft_check_format(line) == -1 || ft_check_max(ft_atoll(line)) == -1 ||
			(ft_atoll(line) > 0 && (ft_atou(line) == 0)) || ft_strlen(line) > 19)
		return (-1);
	return (0);
}

