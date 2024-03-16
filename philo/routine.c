/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/16 14:05:08 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_think(t_philo *philo)
{
	if (!is_end(philo))
		print_state(philo, THINK_MSG);
}

static void	_eat(t_philo *philo)
{
	if (take_fork(philo, &philo->right_fork))
	{
		if (take_fork(philo, philo->left_fork))
		{
			if (!is_end(philo))
			{
				print_state(philo, EAT_MSG);
				philo->last_eat_time = get_time();
				if (philo->arg.eat_credit != INFINI_CREDIT)
					philo->arg.eat_credit--;
				philo_wait(philo, philo->arg.time_to_eat);
			}
			fork_toggle_available(philo->left_fork);
		}
		fork_toggle_available(&philo->right_fork);
	}
}

static void	_sleep(t_philo *philo)
{
	if (!is_end(philo))
	{
		print_state(philo, SLEEP_MSG);
		philo_wait(philo, philo->arg.time_to_sleep);
	}
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	philo->start_time = get_time();
	philo->last_eat_time = philo->start_time;
	if (philo->id % 2)
	{
		_think(philo);
		philo_wait(philo, philo->arg.time_to_eat);
		_eat(philo);
		_sleep(philo);
	}
	while (!is_end(philo) && philo->arg.eat_credit)
	{
		_think(philo);
		_eat(philo);
		_sleep(philo);
	}
	return (NULL);
}
