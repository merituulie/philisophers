/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:34:45 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/14 19:34:45 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h";

static void eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->r_fork_id]);
	printf("%d %i has taken a fork\n", time_ms(), philo->id);
	pthread_mutex_unlock(&philo->data->fork[philo->r_fork_id]);
	if (philo->data->max_philo_id > 1)
	{
		pthread_mutex_lock(&philo->data->fork[philo->l_fork_id]);
		printf("%d %i has taken a fork\n", time_ms(), philo->id);
		pthread_mutex_unlock(&philo->data->fork[philo->l_fork_id]);
		pthread_mutex_lock(&philo->lock);
		philo->time_since_last_meal = time_ms();
		pthread_mutex_unlock(&philo->lock);
		printf("%d %i is eating\n", time_ms(), philo->id);
		usleep(philo->data->time_to_eat);
		if (philo->data->meal_count > 0)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->eat_count++;
			pthread_mutex_unlock(&philo->data->lock);
		}
	}
}

void	simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	pthread_mutex_unlock(&philo->data->lock);
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		printf("%d %i is thinking\n", time_ms(), philo->id);
		eat(philo)
		printf("%d %i is sleeping\n", time_ms(), philo->id);
		usleep(philo->data->time_to_sleep);
	}
}
