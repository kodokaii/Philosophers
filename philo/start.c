/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/16 14:02:52 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_run_philo(t_philo *philo, t_philo_arg *arg, t_fork *first_fork)
{
	pthread_t	philo_thread;
	t_philo		next_philo;

	if (philo->id <= arg->philo_count)
	{
		if (philo->id < arg->philo_count)
		{
			init_philo(&next_philo, arg, philo->id + 1);
			philo->left_fork = &next_philo.right_fork;
			pthread_create(&philo_thread, NULL, &routine, philo);
			_run_philo(&next_philo, arg, first_fork);
		}
		else
		{
			philo->left_fork = first_fork;
			pthread_create(&philo_thread, NULL, &routine, philo);
		}
		pthread_join(philo_thread, NULL);
	}
}

int	run_simulation(t_philo_arg *arg)
{
	t_philo	first_philo;

	init_philo(&first_philo, arg, 1);
	_run_philo(&first_philo, arg, &first_philo.right_fork);
	return (EXIT_SUCCESS);
}
