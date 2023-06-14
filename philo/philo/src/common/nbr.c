/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:34:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/12 18:24:42 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	result;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		if (result > INT_MAX || result < 0)
			return (-1);
		str++;
	}
	return ((int)result);
}
