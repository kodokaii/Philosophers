/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 02:05:43 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	_fork_is_available(t_fork *fork)
{
	t_bool	is_available;

	pthread_mutex_lock(&fork->mutex);
	is_available = fork->available;
	pthread_mutex_unlock(&fork->mutex);
	return (is_available);
}

void	fork_toggle_available(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->available = !fork->available;
	pthread_mutex_unlock(&fork->mutex);
}

t_bool	take_fork(t_philo *philo, t_fork *fork)
{
	while (!_fork_is_available(fork) && !is_end(philo))
		usleep(500);
	if (!is_end(philo))
	{
		fork_toggle_available(fork);
		print_state(philo, FORK_MSG);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}
