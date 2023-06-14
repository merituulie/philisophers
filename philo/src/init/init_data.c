/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:36:08 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/13 16:06:57 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	invalid_input_data(t_data *data)
{
	if (data->max_philo_id < 1 || data->time_to_die < 1
		|| data->time_to_eat < 1 || data->time_to_sleep < 1
		|| data->meal_count <= -1)
	{
		printf("Received negative or overflowing numbers where expecting unsigned integers.\n");
		return (1);
	}
	return (0);
}

int	init(t_data **data, char **input, int argc)
{
	*data = (t_data *)ft_calloc(1, sizeof(**data));
	if (!data || !(*data))
		return (0);
	(*data)->max_philo_id = ft_atoi(input[1]);
	(*data)->time_to_die = ft_atoi(input[2]);
	(*data)->time_to_eat = ft_atoi(input[3]);
	(*data)->time_to_sleep = ft_atoi(input[4]);
	if (argc == 6)
		(*data)->meal_count = ft_atoi(input[5]);
	else
		(*data)->meal_count = 0;
	if (invalid_input_data(*data))
		return (0);
	if (!init_forks(data))
		return (0);
	if (!init_philos(data))
		return (0);
	return (1);
}
