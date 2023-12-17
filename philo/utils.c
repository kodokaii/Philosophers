/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/17 04:56:58 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec - philo->start_time);
}

t_bool	is_end(t_bool trigger)
{
	static t_bool			end = FT_FALSE;
	static pthread_mutex_t	mutex;
	t_bool					result;

	pthread_mutex_lock(&mutex);
	if (trigger)
		end = FT_TRUE;
	result = end;
	pthread_mutex_unlock(&mutex);
	return (result);
}

void	print_state(t_philo *philo, char *str)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&mutex);
	printf("%ld %u %s\n", get_time(philo), philo->id, str);
	pthread_mutex_unlock(&mutex);
}
