/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:50:33 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/19 17:12:31 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

unsigned long long	time_ms(void)
{
	struct timeval			tv;

	if (gettimeofday(&tv, NULL) == 0)
		return (((tv.tv_sec) * (unsigned int)1000) + ((tv.tv_usec) / 1000));
	else
		return (0);
}
