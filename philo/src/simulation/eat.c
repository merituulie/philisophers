/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:43:35 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 18:19:03 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static void	drop_forks(t_philo **philo)
{
	pthread_mutex_unlock(&(*philo)->data->forks[(*philo)->r_fork_id]);
	pthread_mutex_unlock(&(*philo)->data->forks[(*philo)->l_fork_id]);
	pthread_mutex_lock(&(*philo)->lock);
	(*philo)->eating = 0;
	pthread_mutex_unlock(&(*philo)->lock);
}

static int take_fork(t_philo **philo, int right)
{
	if (other_philo_starved(philo))
	{
		drop_forks(philo);
		return (0);
	}
	if (right)
		pthread_mutex_lock(&(*philo)->data->forks[(*philo)->r_fork_id]);
	else
		pthread_mutex_lock(&(*philo)->data->forks[(*philo)->l_fork_id]);
	ft_print(*philo, &(*philo)->data, TAKE_FORK);
	return (1);
}

static int	update_eating(t_philo **philo)
{
	if (other_philo_starved(philo))
	{
		drop_forks(philo);
		return (0);
	}
	pthread_mutex_lock(&(*philo)->lock);
	(*philo)->eating = 1;
	(*philo)->time_to_starve = (time_ms() + (*philo)->data->time_to_die) - (*philo)->data->start_time;
	pthread_mutex_unlock(&(*philo)->lock);
	return (1);
}

static int	update_eat_count(t_philo **philo)
{
	if ((*philo)->data->meal_count == 0)
		return (1);
	if (other_philo_starved(philo))
	{
		drop_forks(philo);
		return (0);
	}
	pthread_mutex_lock(&(*philo)->data->lock);
	(*philo)->data->eat_count++;
	pthread_mutex_unlock(&(*philo)->data->lock);
	return (1);
}

void eat(t_philo *philo)
{
	if (other_philo_starved(&philo))
		return ;
	if (!take_fork(&philo, 1) || !take_fork(&philo, 0))
		return ;
	if (!update_eating(&philo))
		return ;
	ft_print(philo, &philo->data, EAT);
	if (other_philo_starved(&philo))
	{
		drop_forks(&philo);
		return ;
	}
	ft_usleep(philo->data->time_to_eat);
	if (!update_eat_count(&philo))
		return;
	drop_forks(&philo);
}
