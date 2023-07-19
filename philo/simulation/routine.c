/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:24:01 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/19 12:19:35 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	other_philo_starved(t_data **data)
{
	pthread_mutex_lock(&(*data)->lock);
	pthread_mutex_lock(&(*data)->eat_lock);
	if ((*data)->death || (*data)->all_full)
	{
		pthread_mutex_unlock(&(*data)->lock);
		pthread_mutex_unlock(&(*data)->eat_lock);
		return (1);
	}
	pthread_mutex_unlock(&(*data)->lock);
	pthread_mutex_unlock(&(*data)->eat_lock);
	return (0);
}

static int	update_eating(t_philo **philo, t_data **data)
{
	if (other_philo_starved(data))
	{
		drop_forks(philo, data, (*philo)->r_fork_id, (*philo)->l_fork_id);
		return (0);
	}
	pthread_mutex_lock(&(*philo)->lock);
	(*philo)->eating = 1;
	(*philo)->time_since_last_meal = time_mls();
	pthread_mutex_unlock(&(*philo)->lock);
	return (1);
}

static int	update_eat_count(t_philo **philo, t_data **data)
{
	pthread_mutex_lock(&(*philo)->lock);
	if ((*data)->meals_to_eat_per_philo != -1)
	{
		(*philo)->meals_to_eat--;
		if ((*philo)->meals_to_eat <= 0)
		{
			pthread_mutex_unlock(&(*philo)->lock);
			return (0);
		}
	}
	pthread_mutex_unlock(&(*philo)->lock);
	return (1);
}

static int	eat(t_philo **philo, t_data **data)
{
	if (!take_fork(philo, data, 1) || !take_fork(philo, data, 0))
		return (0);
	if (!update_eating(philo, data))
	{
		drop_forks(philo, data, (*philo)->r_fork_id, (*philo)->l_fork_id);
		return (0);
	}
	ft_print(philo, data, EAT, 1);
	if (!ft_usleep((*data)->time_to_eat, data, philo)
		|| !update_eat_count(philo, data))
	{
		drop_forks(philo, data, (*philo)->r_fork_id, (*philo)->l_fork_id);
		return (0);
	}
	drop_forks(philo, data, (*philo)->r_fork_id, (*philo)->l_fork_id);
	return (1);
}

int	routine(t_philo **philo, t_data **data)
{
	if (other_philo_starved(data))
		return (0);
	if (!eat(philo, data))
		return (0);
	ft_print(philo, data, SLEEP, 0);
	if (!ft_usleep((*data)->time_to_sleep, data, philo))
		return (0);
	ft_print(philo, data, THINK, 0);
	return (1);
}
