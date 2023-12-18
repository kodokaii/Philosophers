/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 18:40:14 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_is_dead(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	while (!is_dead(philo))
		usleep(500);
	exit(EXIT_FAILURE);
}

void	wait_fork(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, check_is_dead, philo);
	pthread_detach(thread);
	sem_wait(philo->fork);
	print_state(philo, FORK_MSG);
	exit(EXIT_SUCCESS);
}

t_bool	take_fork(t_philo *philo)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		wait_fork(philo);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		return (FT_TRUE);
	return (FT_FALSE);
}
