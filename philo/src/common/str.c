/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:15:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/12 17:34:38 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	strlength(char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	putstr_fd(char *s, int fd)
{
	int	len;

	len = strlength(s);
	write(fd, s, len);
}
