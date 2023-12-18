/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 19:34:21 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_think(t_philo *philo)
{
	if (!is_dead(philo))
		print_state(philo, THINK_MSG);
}

static void	_eat(t_philo *philo)
{
	if (take_fork(philo))
	{
		if (take_fork(philo))
		{
			print_state(philo, EAT_MSG);
			philo->last_eat_time = get_time();
			if (philo->arg.eat_credit != INFINI_CREDIT)
				philo->arg.eat_credit--;
			philo_wait(philo, philo->arg.time_to_eat);
			sem_post(philo->fork);
		}
		sem_post(philo->fork);
	}
}

static void	_sleep(t_philo *philo)
{
	if (!is_dead(philo))
	{
		print_state(philo, SLEEP_MSG);
		philo_wait(philo, philo->arg.time_to_sleep);
	}
}

void	routine(t_philo *philo)
{
	philo->start_time = get_time();
	philo->last_eat_time = philo->start_time;
	if (philo->id % 2)
	{
		_think(philo);
		philo_wait(philo, philo->arg.time_to_eat);
		_eat(philo);
		_sleep(philo);
	}
	while (!is_dead(philo) && philo->arg.eat_credit)
	{
		_think(philo);
		_eat(philo);
		_sleep(philo);
	}
	if (is_dead(philo))
		print_state(philo, DEAD_MSG);
}
