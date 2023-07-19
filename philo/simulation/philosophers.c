/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:11:25 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/18 19:25:09 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static void	simulate_one(t_philo *philo, t_data *data)
{
	ft_print(&philo, &data, TAKE_FORK_R, 0);
	usleep(data->time_to_die);
	pthread_mutex_lock(&data->lock);
	data->death = 1;
	pthread_mutex_unlock(&data->lock);
}

void	*philosopher(void *thread_struct)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)thread_struct;
	data = *philo->data;
	pthread_mutex_lock(&data->lock);
	pthread_mutex_unlock(&data->lock);
	if (data->philo_count == 1)
	{
		simulate_one(philo, data);
		return (NULL);
	}
	ft_print(&philo, &data, THINK, 0);
	if (philo->id % 2 == 0 || (int)philo->id == data->philo_count)
		ft_usleep(data->time_to_eat * 0.3, &data);
	while (1)
	{
		if (!routine(&philo, &data))
			break ;
	}
	return (NULL);
}
