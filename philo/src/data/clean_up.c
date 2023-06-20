/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:07:43 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 16:49:33 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	clean_up(t_data **data)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&(*data)->lock);
	while (i < (*data)->max_philo_id)
	{
		pthread_mutex_destroy(&(*data)->philos[i].lock);
		pthread_mutex_destroy(&(*data)->forks[i]);
		i++;
	}
	free(*data);
}