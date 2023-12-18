/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 19:28:44 by nlaerema         ###   ########.fr       */
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

void	init_philo(t_philo *philo, t_philo_arg *arg, t_uint id)
{
	philo->fork = sem_open("fork", O_CREAT, 0644, arg->philo_count);
	philo->print = sem_open("print", O_CREAT, 0644, 1);
	philo->id = id;
	philo->start_time = 0;
	philo->last_eat_time = 0;
	philo->arg = *arg;
	sem_unlink("fork");
	sem_unlink("print");
}
