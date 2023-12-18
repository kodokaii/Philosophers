/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 00:58:12 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_end(t_philo *philo)
{
	static t_bool			end = FT_FALSE;
	static pthread_mutex_t	mutex;
	t_bool					is_dead;

	is_dead = FT_FALSE;
	if (!philo->is_end)
	{
		pthread_mutex_lock(&mutex);
		if (!end && get_time_it_die(philo) <= 0)
		{
			is_dead = FT_TRUE;
			end = FT_TRUE;
		}
		philo->is_end = end;
		pthread_mutex_unlock(&mutex);
		if (is_dead)
			print_state(philo, DEAD_MSG);
	}
	return (philo->is_end);
}

void	philo_wait(t_philo *philo, long wait_time)
{
	long	time_it_die;

	time_it_die = get_time_it_die(philo);
	if (time_it_die < wait_time)
		wait_time = time_it_die;
	if (0 < wait_time)
		usleep(wait_time * 1000);
}

void	print_state(t_philo *philo, char *str)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
	long					timestamp;

	timestamp = get_timestamp(philo);
	pthread_mutex_lock(&mutex);
	printf("%ld [%u]: %s\n", timestamp, philo->id, str);
	pthread_mutex_unlock(&mutex);
}
