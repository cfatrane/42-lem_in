/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:52:59 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/26 21:37:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_format_nbr(char *line)
{
	while (*line)
	{
		if (*line == '-' || *line == '+')
			line++;
		if (!ft_isdigit(*line))
			return (-1);
		line++;
	}
	return (0);
}

int		ft_check_max(char *line)
{
	if (ft_atoll(line) < INT_MIN || ft_atoll(line) > INT_MAX)
		return (-1);
	return (0);
}

int		ft_check_format_name(char *str)
{
	int	i;

	i = 0;
	if (str[0] == 'L')
		return (-1);
	while (str[i])
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_error_rooms(char *name, char *coord_x, char *coord_y)
{
	if (ft_check_format_name(name) == -1)
		return (-1);
	if (ft_check_format_nbr(coord_x) == -1 ||
			ft_check_max(coord_x) == -1 || (ft_atoll(coord_x) > 0 &&
				(ft_atou(coord_x) == 0)) ||
			ft_strlen(coord_x) > 19)
		return (-1);
	if (ft_check_format_nbr(coord_y) == -1 ||
			ft_check_max(coord_y) == -1 || (ft_atoll(coord_y) > 0 &&
				(ft_atou(coord_y) == 0)) ||
			ft_strlen(coord_y) > 19)
		return (-1);
	return (0);
}

int		ft_error_nbr(char *line)
{
	if (ft_check_format_nbr(line) == -1 || ft_check_max(line) == -1 ||
			(ft_atoll(line) > 0 && (ft_atou(line) == 0)) ||
			ft_strlen(line) > 19)
		return (-1);
	return (0);
}
