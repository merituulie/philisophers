/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:49:43 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/18 20:21:02 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	philo_starved(t_data **data, int i)
{
	pthread_mutex_lock(&(*data)->eat_lock);
	if ((*data)->all_full)
	{
		pthread_mutex_unlock(&(*data)->eat_lock);
		return (0);
	}
	pthread_mutex_unlock(&(*data)->eat_lock);
	if (starved(data, i))
	{
		pthread_mutex_lock(&(*data)->lock);
		(*data)->death = 1;
		pthread_mutex_unlock(&(*data)->lock);
		ft_printf_died(&(*data)->philos[i], (*data));
		return (1);
	}
	return (0);
}

static int	all_ate(t_data **data, int i)
{
	static int	ate_count;

	if ((*data)->meals_to_eat_per_philo == -1)
		return (0);
	if (philo_ate_enough(data, i))
		ate_count++;
	if (ate_count >= (*data)->philo_count)
	{
		pthread_mutex_lock(&(*data)->eat_lock);
		(*data)->all_full = 1;
		pthread_mutex_unlock(&(*data)->eat_lock);
		return (1);
	}
	else
		return (0);
}

static int	supervise(t_data **data)
{
	int	i;

	pthread_mutex_unlock(&(*data)->lock);
	while (1)
	{
		i = 0;
		while (i < ((*data)->philo_count))
		{
			if (all_ate(data, i) || philo_starved(data, i))
			{
				if (!stop_threads(data))
					return (0);
				else
					return (1);
			}
			i++;
		}
		usleep(40);
	}
	return (1);
}

int	dine(t_data **data)
{
	if (pthread_mutex_lock(&(*data)->lock) != 0)
	{
		printf("Could not make threads wait in the beginning of the sim.\n");
		return (0);
	}
	if (!start_threads(data))
		return (0);
	(*data)->start_time = time_mls();
	if (!supervise(data))
		return (0);
	clean(data);
	return (1);
}
