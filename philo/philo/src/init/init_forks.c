/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:31:54 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/13 15:42:07 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	init_forks(t_data **data)
{
	int i;
	t_fork	*forks;

	forks = (t_fork *)ft_calloc((*data)->max_philo_id, sizeof(*forks));
	if (!forks)
	{
		printf("Error in allocating memory for the forks.\n");
		return (0);
	}
	i = 0;
	while (i < (*data)->max_philo_id)
	{
		forks[i].id = i + 1;
		if (pthread_mutex_init(&forks[i].lock, NULL) != 0)
		{
			printf("Error in initializing a mutex for a fork %i.\n", i);
			return (0);
		}
		i++;
	}
	(*data)->forks = forks;
	return (1);
}
