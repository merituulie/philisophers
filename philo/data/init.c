/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:42:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/18 20:08:43 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	invalid_input_data(t_data *data)
{
	if (data->philo_count < 1 || data->philo_count > 200
		|| (data->time_to_die < 1 || data->time_to_die > INT_MAX)
		|| (data->time_to_eat < 1 || data->time_to_eat > INT_MAX)
		|| (data->time_to_sleep < 1 || data->time_to_sleep > INT_MAX)
		|| (data->meals_to_eat_per_philo < -1
			|| data->meals_to_eat_per_philo == 0))
	{
		printf("Received zero, negative or overflowing numbers.\n");
		return (1);
	}
	return (0);
}

static int	init_lock(t_data **data)
{
	if (pthread_mutex_init(&(*data)->lock, NULL) != 0)
	{
		printf("Error in initializing a mutex for the data.\n");
		return (0);
	}
	return (1);
}

static int	init_data(t_data **data, char **input, int argc)
{
	*data = (t_data *)ft_calloc(1, sizeof(**data));
	if (!data || !(*data))
		return (0);
	(*data)->death = 0;
	(*data)->start_time = 0;
	(*data)->philo_count = ft_atoi(input[1]);
	(*data)->time_to_die = ft_atoi(input[2]);
	(*data)->time_to_eat = ft_atoi(input[3]);
	(*data)->time_to_sleep = ft_atoi(input[4]);
	(*data)->threads = (pthread_t *)ft_calloc((*data)->philo_count,
			sizeof(pthread_t));
	if (argc == 6)
	{
		(*data)->meals_to_eat_per_philo = ft_atoi(input[5]);
		if ((*data)->meals_to_eat_per_philo == -1)
			(*data)->meals_to_eat_per_philo = -2;
	}
	else
		(*data)->meals_to_eat_per_philo = -1;
	return (init_lock(data));
}

int	init(t_data **data, char **input, int argc)
{
	if (!init_data(data, input, argc))
		return (0);
	if (invalid_input_data(*data))
		return (0);
	if (!init_forks(data))
		return (0);
	if (!init_philos(data))
		return (0);
	if (pthread_mutex_init(&(*data)->print_lock, NULL) != 0
		|| pthread_mutex_init(&(*data)->eat_lock, NULL) != 0)
	{
		printf("Issue with initializing the mutex.\n");
		return (0);
	}
	return (1);
}
