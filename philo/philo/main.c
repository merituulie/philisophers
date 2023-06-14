/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:13:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/13 18:05:05 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/philo.h"

/*
TODO
	set the start time, time_since_last_meal
*/

int	main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	if (invalid_input(argc, argv))
		return (EXIT_FAILURE);
	else if (!init(&data, argv, argc))
		return (EXIT_FAILURE);
	printf("philos: %d\n", data->max_philo_id);
	printf("die: %d\n", data->time_to_die);
	printf("eat: %d\n", data->time_to_eat);
	printf("sleep: %d\n", data->time_to_sleep);
	printf("count: %d\n\n", data->meal_count);

	printf("philo [%d] with values %d, %d, %d, %d\n", data->philos[0].id, data->philos[0].r_fork_id, data->philos[0].l_fork_id, data->philos[0].meals_eaten, data->philos[0].time_since_last_meal);
	printf("philo [%d] with values %d, %d, %d, %d\n", data->philos[1].id, data->philos[1].r_fork_id, data->philos[1].l_fork_id, data->philos[1].meals_eaten, data->philos[1].time_since_last_meal);
	printf("philo [%d] with values %d, %d, %d, %d\n", data->philos[2].id, data->philos[2].r_fork_id, data->philos[2].l_fork_id, data->philos[2].meals_eaten, data->philos[2].time_since_last_meal);
	printf("philo [%d] with values %d, %d, %d, %d\n", data->philos[3].id, data->philos[3].r_fork_id, data->philos[3].l_fork_id, data->philos[3].meals_eaten, data->philos[3].time_since_last_meal);
	printf("philo [%d] with values %d, %d, %d, %d\n", data->philos[4].id, data->philos[4].r_fork_id, data->philos[4].l_fork_id, data->philos[4].meals_eaten, data->philos[4].time_since_last_meal);
	printf("philo [%d] with values %d, %d, %d, %d\n\n", data->philos[5].id, data->philos[5].r_fork_id, data->philos[5].l_fork_id, data->philos[5].meals_eaten, data->philos[5].time_since_last_meal);

	printf("fork [%d]\n", data->forks[0].id);
	printf("fork [%d]\n", data->forks[1].id);
	printf("fork [%d]\n", data->forks[2].id);
	printf("fork [%d]\n", data->forks[3].id);
	printf("fork [%d]\n", data->forks[4].id);
	printf("fork [%d]\n", data->forks[5].id);
	return (0);
}
