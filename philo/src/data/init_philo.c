/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:27:32 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 16:35:51 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	init_philo(t_data **data, t_philo *new, int id)
{
	new->data = *data;
	new->id = id + 1;
	new->meals_eaten = 0;
	new->eating = 0;
	if (new->id == 1)
	{
		new->r_fork_id = (*data)->max_philo_id - 1;
		new->l_fork_id = 0;
	}
	else
	{
		new->r_fork_id = new->id - 2;
		new->l_fork_id = new->id - 1;
	}
	if (pthread_mutex_init(&new->lock, NULL) != 0)
	{
		printf("Issue with initializing the mutex for the philo %i.\n", id);
		return (0);
	}
	new->time_to_starve = (*data)->time_to_die;
	return (1);
}

int	init_philos(t_data **data)
{
	int	i;

	(*data)->philos = (t_philo *)ft_calloc((*data)->max_philo_id, sizeof(t_philo));
	if (!(*data)->philos)
	{
		printf("Error in allocating memory for philos.\n");
		return (0);
	}
	i = 0;
	while (i <= ((*data)->max_philo_id - 1))
	{
		if (!init_philo(data, &(*data)->philos[i], i))
			return (0);
		i++;
	}
	printf("%i philos created\n", i);
	return (1);
}