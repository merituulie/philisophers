/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:44:30 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/18 20:15:38 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	invalid_count(int arg_count)
{
	if (arg_count < 5 || arg_count > 6)
	{
		printf("Invalid number %i of arguments where only 4 to 5 expected.\n",
			arg_count - 1);
		return (1);
	}
	return (0);
}

static int	not_digit(char c)
{
	if (c < 48 || c > 57)
	{
		printf("Invalid type of argument '%c' where only numbers expected.\n",
			c);
		return (1);
	}
	return (0);
}

static int	invalid_chars(char **input)
{
	int	i;
	int	j;

	i = 1;
	if (!input[i])
		return (1);
	while (input[i])
	{
		j = 0;
		if (!input[i][j])
		{
			printf("Expected to find at least one character.\n");
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

static int	invalid_meal_count(int arg_count, char **input)
{
	if (arg_count == 6 && input[5][0] == '0')
	{
		printf("Expected the meal count to be more than 0.\n");
		return (1);
	}
	return (0);
}

int	invalid_input(int arg_count, char **input)
{
	if (invalid_meal_count(arg_count, input))
		return (1);
	if (invalid_count(arg_count))
		return (1);
	if (invalid_chars(input))
		return (1);
	return (0);
}
