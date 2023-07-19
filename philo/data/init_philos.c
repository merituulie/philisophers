/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:18:26 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/18 18:45:55 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	init_philo(t_data **data, t_philo *new, int id)
{
	new->data = data;
	new->id = id + 1;
	new->meals_to_eat = (*data)->meals_to_eat_per_philo;
	new->eating = 0;
	new->time_of_death = 0;
	if (new->id == 1)
	{
		new->r_fork_id = (*data)->philo_count - 1;
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
	new->time_since_last_meal = 0;
	return (1);
}

int	init_philos(t_data **data)
{
	int		i;

	(*data)->philos = (t_philo *)ft_calloc((*data)->philo_count,
			sizeof(t_philo));
	if (!(*data)->philos)
	{
		printf("Error in allocating memory for philos.\n");
		return (0);
	}
	i = 0;
	while (i <= ((*data)->philo_count - 1))
	{
		if (!init_philo(data, &(*data)->philos[i], i))
			return (0);
		i++;
	}
	return (1);
}
