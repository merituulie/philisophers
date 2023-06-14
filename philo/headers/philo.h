/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:16:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/13 15:36:40 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_fork
{
	int	id;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_data
{
	int	max_philo_id;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	start_time;
	int	meal_count; // number_of_times_each_philosopher_must_eat
	struct s_fork	*forks;
	struct s_philo	*philos;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	id;
	unsigned int	time_since_last_meal;
	unsigned int	meals_eaten;
	unsigned int	r_fork_id;
	unsigned int	l_fork_id;
	struct s_data	*data;
	pthread_mutex_t	lock;
}	t_philo;

// COMMON
int				strlength(char *s);
void			putstr_fd(char *s, int fd);
unsigned int	time_ms(void);
int				invalid_input(int arg_count, char **input);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);

// PHILO
int				init(t_data **data, char **input, int argc);
int				init_philos(t_data **data);
int				init_forks(t_data **data);

#endif
