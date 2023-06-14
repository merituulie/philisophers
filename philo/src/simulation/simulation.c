/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:34:45 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/14 19:34:45 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	simulation(t_data **data)
{
	pthread_mutex_lock(&data->lock);
	pthread_mutex_unlock(&data->lock);
}
