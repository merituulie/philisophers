/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:51:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/04 18:59:57 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	init_forks(t_data **data)
{
	int	i;

	(*data)->forks = (pthread_mutex_t *)ft_calloc((*data)->philo_count,
			sizeof(*(*data)->forks));
	if (!(*data)->forks)
	{
		printf("Error in allocating memory for the forks.\n");
		return (0);
	}
	i = 0;
	while (i < (*data)->philo_count)
	{
		if (pthread_mutex_init(&(*data)->forks[i], NULL) != 0)
		{
			printf("Error in initializing a mutex for a fork %i.\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}
