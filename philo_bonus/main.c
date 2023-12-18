/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/18 18:23:24 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_arg_error(void)
{
	write(2, "Invalid Argument !\n", 19);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_philo_arg	arg;

	if (init_arg(&arg, --argc, ++argv))
		return (_arg_error());
	return (run_simulation(&arg));
}
