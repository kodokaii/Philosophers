/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/17 04:52:31 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_bool
{
	FT_FALSE	= 0,
	FT_TRUE		= 1
}	t_bool;

typedef unsigned int	t_uint;

typedef struct s_philo
{
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	t_uint			id;
	t_uint			eat_credit;	
	long			start_time;
	long			last_eat_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
}	t_philo;

#endif
