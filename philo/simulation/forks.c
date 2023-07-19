/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/18 20:16:02 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	drop_forks(t_philo **philo, t_data **data, int r_fork_id, int l_fork_id)
{
	pthread_mutex_lock(&(*philo)->lock);
	if (r_fork_id > -1)
		pthread_mutex_unlock(&(*data)->forks[r_fork_id]);
	if (l_fork_id > -1)
		pthread_mutex_unlock(&(*data)->forks[l_fork_id]);
	(*philo)->eating = 0;
	pthread_mutex_unlock(&(*philo)->lock);
}

int	take_fork(t_philo **philo, t_data **data, int right)
{
	if (right)
	{
		pthread_mutex_lock(&(*data)->forks[(*philo)->r_fork_id]);
		ft_print(philo, data, TAKE_FORK_R, 1);
	}
	else
	{
		pthread_mutex_lock(&(*data)->forks[(*philo)->l_fork_id]);
		ft_print(philo, data, TAKE_FORK_L, 1);
	}
	return (1);
}
