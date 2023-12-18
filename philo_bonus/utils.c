/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 20:35:43 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_dead(t_philo *philo)
{
	return (get_time_it_die(philo) <= 0);
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
	long					timestamp;

	timestamp = get_timestamp(philo);
	sem_wait(philo->print);
	printf("%ld [%u]: %s\n", timestamp, philo->id, str);
	if (!is_dead(philo))
		sem_post(philo->print);
}
