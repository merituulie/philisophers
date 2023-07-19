/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:52:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/04 16:42:11 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

unsigned long long	time_mls(void)
{
	struct timeval			tv;

	if (gettimeofday(&tv, NULL) == 0)
		return (((tv.tv_sec) * (unsigned int)1000) + ((tv.tv_usec) / 1000));
	else
		return (0);
}
