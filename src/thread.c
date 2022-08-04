/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:21:19 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/05 01:03:11 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	info_msg(t_time time, int id, char *msg)
{
	printf("%d %d %s\n", time.tv_usec, id, msg);
}

void	philo_eat(t_philo *philo, int eat_time)
{
	pthread_mutex_lock(&philo->fork_right);
	info_msg(get_time(), philo->id, FORK_MESSAGE);
	pthread_mutex_lock(&philo->fork_left);
	info_msg(get_time(), philo->id, FORK_MESSAGE);
	philo->time_last_eat = get_time();
	info_msg(philo->time_last_eat, philo->id, EAT_MESSAGE);
	usleep(eat_time);
	if (philo->id != 2)
	{
		pthread_mutex_unlock(&philo->fork_right);
		pthread_mutex_unlock(&philo->fork_left);
	}
}

void	philo_sleep(t_philo *philo, int sleep_time)
{
	info_msg(get_time(), philo->id, SLEEP_MESSAGE);
	usleep(sleep_time);
}

void	philo_think(t_philo *philo)
{
	info_msg(get_time(), philo->id, THINK_MESSAGE);
	usleep(100000);
}

void	*philo_main(void *args)
{
	t_philo *philo;

	philo = (t_philo *) args;
	philo->time_last_eat = get_time();
	while (1)
	{
		philo_eat(philo, 100);
		philo_sleep(philo, 100);
		philo_think(philo);
	}
	return (NULL);
}

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
