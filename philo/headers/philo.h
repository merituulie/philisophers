/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:10:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/07/18 20:20:26 by meskelin         ###   ########.fr       */
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

# ifndef EAT
#  define EAT 2
# endif

# ifndef SLEEP
#  define SLEEP 3
# endif

# ifndef THINK
#  define THINK 4
# endif

# ifndef TAKE_FORK_R
#  define TAKE_FORK_R 5
# endif

# ifndef TAKE_FORK_L
#  define TAKE_FORK_L 6
# endif

struct	s_philo;

typedef struct s_data
{
	int					philo_count;
	int					all_full;
	int					death;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	unsigned long long	start_time;
	int					meals_to_eat_per_philo;
	struct s_philo		*philos;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		eat_lock;
}	t_data;

typedef struct s_philo
{
	int					eating;
	int					full;
	unsigned int		id;
	unsigned long long	time_since_last_meal;
	unsigned long long	time_of_death;
	int					meals_to_eat;
	unsigned int		r_fork_id;
	unsigned int		l_fork_id;
	struct s_data		**data;
	pthread_mutex_t		lock;
}	t_philo;

// COMMON
int						invalid_input(int arg_count, char **input);
int						ft_atoi(const char *str);
void					*ft_calloc(size_t count, size_t size);
unsigned long long		time_mls(void);
void					ft_usleep(unsigned long long time, t_data **data);
void					ft_printf_died(t_philo *philo, t_data *data);
void					ft_print(t_philo **philo, t_data **data, int msg,
							int has_forks);
int						keep_looping(t_data **data);

// DATA
int						init_forks(t_data **data);
int						init_philos(t_data **data);
int						init(t_data **data, char **input, int argc);
void					clean(t_data **data);

// SIMULATION
void					*philosopher(void *thread_struct);
int						dine(t_data **data);
int						take_fork(t_philo **philo, t_data **data, int right);
int						routine(t_philo **philo, t_data **data);
void					drop_forks(t_philo **philo, t_data **data,
							int r_fork_id, int l_fork_id);
int						start_threads(t_data **data);
int						stop_threads(t_data **data);
int						starved(t_data **data, int i);
int						philo_ate_enough(t_data **data, int i);

#endif
