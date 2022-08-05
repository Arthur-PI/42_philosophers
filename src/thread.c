/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:21:19 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/05 11:55:00 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_thread(t_philo_infos infos, t_philo *philos)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(infos.nb_philo * sizeof(*threads));
	if (!threads)
		return (THREAD_INIT_ERROR);
	i = 0;
	while (i < infos.nb_philo)
	{
		pthread_create(threads + i, NULL, &philo_main, philos + i);
		i++;
	}
	i = 0;
	while (i < infos.nb_philo)
		pthread_join(threads[i++], NULL);
	(void)infos;
	(void)philos;
	return (ALL_GOOD);
}
