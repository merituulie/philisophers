/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:55:04 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 18:09:35 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	all_meals_done(t_data **data)
{
	if ((*data)->meal_count == 0)
		return (0);
	pthread_mutex_lock(&(*data)->lock);
	if ((*data)->eat_count >= ((*data)->meal_count * (*data)->max_philo_id))
	{
		(*data)->death = 1;
		pthread_mutex_unlock(&(*data)->lock);
		return (1);
	}
	pthread_mutex_unlock(&(*data)->lock);
	return (0);
}

int philo_starved(t_data **data, int i)
{
	if ((*data)->philos[i].time_to_starve <= (time_ms() - (*data)->start_time)
		&& !(*data)->philos[i].eating)
	{
		pthread_mutex_lock(&(*data)->philos[i].lock);
		(*data)->death = 1;
		pthread_mutex_unlock(&(*data)->philos[i].lock);
		ft_print(&(*data)->philos[i], data, DEAD);
		return (1);
	}
	pthread_mutex_unlock(&(*data)->philos[i].lock);
	return (0);
}

int other_philo_starved(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->data->lock);
	if ((*philo)->data->death)
	{
		pthread_mutex_unlock(&(*philo)->data->lock);
		return (1);
	}
	pthread_mutex_unlock(&(*philo)->data->lock);
	return (0);
}
