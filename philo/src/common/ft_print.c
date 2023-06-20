/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:13:30 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 18:10:11 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static void	print_msg(t_philo *philo, t_data **data, int msg)
{
	if (msg == EAT)
		printf("%llu %i is eating\n", (time_ms() - (*data)->start_time), philo->id);
	else if (msg == SLEEP)
		printf("%llu %i is sleeping\n", (time_ms() - philo->data->start_time), philo->id);
	else if (msg == THINK)
		printf("%llu %i is thinking\n", (time_ms() - (*data)->start_time), philo->id);
	else if (msg == TAKE_FORK)
		printf("%llu %i has taken a fork\n", (time_ms() - philo->data->start_time), philo->id);
}

void	ft_print(t_philo *philo, t_data **data, int msg)
{
	if (msg == DEAD)
	{
		printf("%llu %i died\n", time_ms() - (*data)->start_time, philo->id);
		return ;
	}
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->death)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return ;
	}
	pthread_mutex_unlock(&philo->data->lock);
	print_msg(philo, data, msg);
}
