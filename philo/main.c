/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:13:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/18 20:09:54 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/philo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (invalid_input(argc, argv))
		return (1);
	else if (!init(&data, argv, argc))
	{
		clean(&data);
		return (1);
	}
	dine(&data);
	return (0);
}
