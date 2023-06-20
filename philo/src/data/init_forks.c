/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:31:54 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 16:36:02 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	init_forks(t_data **data)
{
	int i;

	(*data)->forks = (pthread_mutex_t *)ft_calloc((*data)->max_philo_id, sizeof(*(*data)->forks));
	if (!(*data)->forks)
	{
		printf("Error in allocating memory for the forks.\n");
		return (0);
	}
	i = 0;
	while (i < (*data)->max_philo_id)
	{
		if (pthread_mutex_init(&(*data)->forks[i], NULL) != 0)
		{
			printf("Error in initializing a mutex for a fork %i.\n", i);
			return (0);
		}
		i++;
	}
	printf("%i forks created\n", i);
	return (1);
}
