/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:34:45 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 18:12:38 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	*simulation(void *thread_struct)
{
	t_philo *philo;

	philo = (t_philo *)thread_struct;
	pthread_mutex_lock(&philo->data->lock);
	pthread_mutex_unlock(&philo->data->lock);
	ft_print(philo, &philo->data,  THINK);
	if (philo->data->max_philo_id == 1)
	{
		usleep(philo->data->time_to_die);
		return (NULL);
	}
	if (philo->id % 2 == 0 || philo->id == (unsigned int)philo->data->max_philo_id)
		ft_usleep(philo->data->time_to_die / 2);
	while (!philo->data->death)
	{
		if (other_philo_starved(&philo))
			return (NULL);
		eat(philo);
		if (other_philo_starved(&philo))
			return (NULL);
		ft_print(philo, &philo->data, SLEEP);
		ft_usleep(philo->data->time_to_sleep);
		ft_print(philo, &philo->data,  THINK);
	}
	return (NULL);
}
