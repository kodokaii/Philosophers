/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 01:52:00 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_arg(long *l, char *arg)
{
	char	*end;

	*l = ft_strtol(arg, &end);
	if (*end || errno == ERANGE || *l <= 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	init_fork(t_fork *fork)
{
	pthread_mutex_init(&fork->mutex, NULL);
	fork->available = FT_TRUE;
}

int	init_arg(t_philo_arg *arg, int argc, char **argv)
{
	if (argc < 4 || 5 < argc)
		return (EXIT_FAILURE);
	memset(arg, 0, sizeof(t_philo_arg));
	if (get_arg(&arg->philo_count, argv[0]))
		return (EXIT_FAILURE);
	if (get_arg(&arg->time_to_die, argv[1]))
		return (EXIT_FAILURE);
	if (get_arg(&arg->time_to_eat, argv[2]))
		return (EXIT_FAILURE);
	if (get_arg(&arg->time_to_sleep, argv[3]))
		return (EXIT_FAILURE);
	if (argc == 5)
	{
		if (get_arg(&arg->eat_credit, argv[4]))
			return (EXIT_FAILURE);
	}
	else
		arg->eat_credit = INFINI_CREDIT;
	return (EXIT_SUCCESS);
}

void	init_philo(t_philo **philo, t_philo_arg *arg, t_uint id)
{
	*philo = malloc(sizeof(t_philo));
	init_fork(&(*philo)->right_fork);
	(*philo)->left_fork = NULL;
	(*philo)->id = id;
	(*philo)->start_time = 0;
	(*philo)->last_eat_time = 0;
	(*philo)->is_end = FT_FALSE;
	(*philo)->arg = *arg;
}
