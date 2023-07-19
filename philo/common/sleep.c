/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:18:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/12 14:40:35 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	keep_looping(t_data **data)
{
	pthread_mutex_lock(&(*data)->lock);
	if (!(*data)->death)
	{
		pthread_mutex_unlock(&(*data)->lock);
		return (1);
	}
	pthread_mutex_unlock(&(*data)->lock);
	return (0);
}

void	ft_usleep(unsigned long long time, t_data **data)
{
	unsigned long long	start;

	start = time_mls();
	while (keep_looping(data))
	{
		if (time_mls() - start >= time)
			break ;
		usleep(500);
	}
}
