/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:21:19 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/07 15:51:08 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_thread_args	get_thread_args(t_philo_infos *infos, t_philo *philo)
{
	t_thread_args	args;

	args.infos = infos;
	args.philo = philo;
	return (args);
}

int	init_thread(t_philo_infos *infos, t_philo *philos)
{
	int				i;
	pthread_t		*threads;

	threads = malloc(infos->nb_philo * sizeof(*threads));
	if (!threads)
		return (THREAD_INIT_ERROR);
	infos->start_time = get_time(0);
	i = 0;
	while (i < infos->nb_philo)
	{
		pthread_create(threads + i, NULL, &philo_main, philos + i);
		i++;
	}
	i = 0;
	while (i < infos->nb_philo)
		pthread_join(threads[i++], NULL);
	return (ALL_GOOD);
}
