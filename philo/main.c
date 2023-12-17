/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/17 03:50:25 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_1(void *arg)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	(void)arg;
	pthread_mutex_lock(&mutex);
	printf("Nous sommes dans le thread.\n");
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, thread_1, NULL);
	pthread_create(&thread2, NULL, thread_1, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return (EXIT_SUCCESS);
}
