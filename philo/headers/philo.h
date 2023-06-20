/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:16:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/20 18:05:44 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef DEAD
#  define DEAD 1
# endif

# ifndef EAT
#  define EAT 2
# endif

# ifndef SLEEP
#  define SLEEP 3
# endif

# ifndef THINK
#  define THINK 4
# endif

# ifndef TAKE_FORK
#  define TAKE_FORK 5
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

struct t_philo;

typedef struct s_data
{
	int					max_philo_id;
	int					death;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	unsigned long long	start_time;
	unsigned int		meal_count; // number_of_times_each_philosopher_must_eat
	unsigned int		eat_count;
	struct s_philo		*philos;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
}	t_data;

typedef struct s_philo
{
	int					eating;
	unsigned int		id;
	unsigned long long	time_to_starve;
	unsigned int		meals_eaten;
	unsigned int		r_fork_id;
	unsigned int		l_fork_id;
	struct s_data		*data;
	pthread_mutex_t		lock;
}	t_philo;

// COMMON
unsigned long long	time_ms(void);
unsigned long long	ft_usleep(unsigned long long time);
int					invalid_input(int arg_count, char **input);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
void				ft_print(t_philo *philo, t_data **data, int msg);

// PHILO
int					init(t_data **data, char **input, int argc);
int					init_philos(t_data **data);
int					init_forks(t_data **data);
void				clean_up(t_data **data);

// SIMULATION
void				*simulation(void *thread_struct);
int					philosophers(t_data **data);

// THREADS
int					start_threads(t_data **data);
int					stop_threads(t_data **data);

// CHECK
int					all_meals_done(t_data **data);
int					philo_starved(t_data **data, int i);
int					other_philo_starved(t_philo **philo);

// EAT
void				eat(t_philo *philo);

#endif
