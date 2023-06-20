/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:13:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 17:54:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/philo.h"

// handle 1 philosopher
// handle returning philosophers back

int	main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	if (invalid_input(argc, argv))
		return (EXIT_FAILURE);
	else if (!init(&data, argv, argc))
		return (EXIT_FAILURE);
	philosophers(&data);
	return (0);
}
