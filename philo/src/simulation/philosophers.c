/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:02:29 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/14 18:02:29 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static void	supervise(t_philo *philos, int *death)
{
	int i;

	while (1)
	{
		i = 1;
		pthread_mutex_lock(&philos->data->lock);
		if (meal_count != 0 && eat_count >= (meal_count * philos->data->max_philo_id))
			break ;
		pthread_mutex_unlock(&philos->data->lock);
		while (i < philos->data->max_philo_id)
		{
			pthread_mutex_lock(&philos[i]->lock);
			if (philos[i]->time_since_last_meal > philos->data->time_to_die)
			{
				pthread_mutex_unlock(&philos[i]->lock);
				printf("%d %i died\n", time_ms(), philos[i]->id);
				break ;
			}
			pthread_mutex_unlock(&philos[i]->lock);
			i++;
		}
		usleep(250);
	}
}

static int start_threads(t_data **data)
{
	int i;

	i = 0;
	while (i < (*data)->max_philo_id)
	{
		if (pthread_create(&(*data)->philos[i], (*data)->philos[i], &simulation, NULL) != 0)
		{
			printf("Could not create a thread.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	philosophers(t_data **data)
{
	if (pthread_mutex_lock(&(*data)->lock) != 0)
	{
		printf("Could not make threads wait in the beginning of the simulation.\n");
		return (0);
	}
	if (!start_threads(data))
		return (0);
	(*data)->start_time = time_ms();
	pthread_mutex_unlock(&(*data)->lock);
	supervise((*data)->philos, &(*data)->death);
	clean_up(data);
	return (0);
}
