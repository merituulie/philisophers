/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:02:29 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 17:52:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	supervise(t_data **data)
{
	int i;

	pthread_mutex_unlock(&(*data)->lock);
	while (1)
	{
		if (all_meals_done(data))
			break ;
		i = 0;
		while (i <= ((*data)->max_philo_id - 1))
		{
			if (philo_starved(data, i))
			{
				if (!stop_threads(data))
					return (0);
				else
					return (1);
			}
			i++;
		}
		ft_usleep(200);
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
	if (!supervise(data))
		return (0);
	clean_up(data);
	return (1);
}
