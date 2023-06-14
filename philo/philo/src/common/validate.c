/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:44:30 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/13 10:24:09 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int invalid_count(int arg_count)
{
	if (arg_count < 5 || arg_count > 6)
	{
		printf("Invalid number %i of arguments where only 4 to 5 expected.\n", arg_count - 1);
		return (1);
	}
	return (0);
}

static int not_digit(char c)
{
	if (c < 48 || c > 57)
	{
		printf("Invalid type of argument '%c' where only numbers are expected.\n", c);
		return (1);
	}
	return (0);
}

int	invalid_input(int arg_count, char **input)
{
	int	i;
	int	j;

	if (invalid_count(arg_count))
		return (1);
	i = 1;
	if (!input[i])
		return (1);
	while (input[i])
	{
		j = 0;
		if (!input[i][j])
		{
			printf("Expected to find at least one character but found NULL as the %i. argument.\n", i);
			return (1);
		}
		while (input[i][j])
		{
			if (not_digit(input[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
