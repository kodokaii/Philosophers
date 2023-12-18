/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 20:40:19 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_run_philo(t_philo *philo)
{
	pid_t	pid;

	if (philo->id <= philo->arg.philo_count)
	{
		pid = fork();
		if (pid == 0)
		{
			routine(philo);
			exit(EXIT_SUCCESS);
		}
		if (philo->id < philo->arg.philo_count)
		{
			philo->id++;
			_run_philo(philo);
		}
		else
			waitpid(-1, NULL, 0);
		kill(pid, SIGINT);
	}
}

int	run_simulation(t_philo_arg *arg)
{
	t_philo	philo;

	init_philo(&philo, arg, 1);
	_run_philo(&philo);
	return (EXIT_SUCCESS);
}
