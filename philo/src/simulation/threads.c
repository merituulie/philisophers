/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:56:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 17:54:27 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int start_threads(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->max_philo_id)
	{
		if (pthread_create(&(*data)->threads[i], NULL, &simulation, &(*data)->philos[i]))
		{
			printf("Could not create a thread.\n");
			return (0);
		}
		ft_usleep(1);
		i++;
	}
	printf("%i threads created\n", i);
	return (1);
}

int	stop_threads(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->max_philo_id)
	{
		printf("Joining thread %i\n", i);
		if (pthread_join((*data)->threads[i], NULL) != 0)
		{
			printf("Error while joining a thread %i.\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}
