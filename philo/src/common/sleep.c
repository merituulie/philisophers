/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:05 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/19 17:35:27 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

unsigned long long	ft_usleep(unsigned long long time)
{
	unsigned long long	start;

	start = time_ms();
	while ((time_ms() - start) < time)
		usleep(time / 10);
	return (0);
}
