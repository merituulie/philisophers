/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:13:30 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/19 12:13:55 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static void	print_msg(t_philo *philo, t_data **data, int msg)
{
	if (msg == EAT)
		printf("%llu %i is eating\n",
			(time_mls() - (*data)->start_time), philo->id);
	else if (msg == SLEEP)
		printf("%llu %i is sleeping\n",
			(time_mls() - (*data)->start_time), philo->id);
	else if (msg == THINK)
		printf("%llu %i is thinking\n",
			(time_mls() - (*data)->start_time), philo->id);
	else if (msg == TAKE_FORK_R)
		printf("%llu %i has taken a fork\n",
			(time_mls() - (*data)->start_time), philo->id);
	else if (msg == TAKE_FORK_L)
		printf("%llu %i has taken a fork\n",
			(time_mls() - (*data)->start_time), philo->id);
}

// TODO check the time of death, not current time
void	ft_printf_died(t_philo *philo, t_data *data)
{
	printf("%llu %i died\n", time_mls() - data->start_time, philo->id);
}

static void	handle_forks(t_philo **philo, t_data **data, int msg)
{
	if (msg == TAKE_FORK_R)
		drop_forks(philo, data, (*philo)->r_fork_id, -1);
	else if (msg == TAKE_FORK_L)
		drop_forks(philo, data, -1, (*philo)->l_fork_id);
	else
		drop_forks(philo, data, (*philo)->r_fork_id,
			(*philo)->l_fork_id);
}

void	ft_print(t_philo **philo, t_data **data, int msg, int has_forks)
{
	pthread_mutex_lock(&(*data)->print_lock);
	pthread_mutex_lock(&(*data)->lock);
	if ((*data)->death)
	{
		pthread_mutex_unlock(&(*data)->lock);
		pthread_mutex_unlock(&(*data)->print_lock);
		if (has_forks)
			handle_forks(philo, data, msg);
		return ;
	}
	pthread_mutex_unlock(&(*data)->lock);
	print_msg(*philo, data, msg);
	pthread_mutex_unlock(&(*data)->print_lock);
}
