/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 02:01:15 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <errno.h>

# define INFINI_CREDIT -1

# define FORK_MSG	"has taken a fork"
# define EAT_MSG	"is eating"
# define SLEEP_MSG	"is sleeping"
# define THINK_MSG	"is thinking"
# define DEAD_MSG	"died"

typedef enum e_bool
{
	FT_FALSE	= 0,
	FT_TRUE		= 1
}	t_bool;

typedef unsigned int	t_uint;

typedef struct s_philo_arg
{
	long	philo_count;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	eat_credit;
}	t_philo_arg;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	t_bool			available;
}	t_fork;

typedef struct s_philo
{
	t_fork		right_fork;
	t_fork		*left_fork;
	t_uint		id;
	long		start_time;
	long		last_eat_time;
	t_bool		is_end;
	t_philo_arg	arg;
}	t_philo;

void	fork_toggle_available(t_fork *fork);
t_bool	take_fork(t_philo *philo, t_fork *fork);
void	*routine(void *ptr);

int		run_simulation(t_philo_arg *arg);

void	init_philo(t_philo **philo, t_philo_arg *arg, t_uint id);
int		init_arg(t_philo_arg *arg, int argc, char **argv);

long	get_time(void);
long	get_timestamp(t_philo *philo);
long	get_time_it_die(t_philo *philo);

t_bool	is_end(t_philo *philo);
void	philo_wait(t_philo *philo, long wait_time);
void	print_state(t_philo *philo, char *str);

long	ft_strtol(const char *str, char **endptr);

#endif
