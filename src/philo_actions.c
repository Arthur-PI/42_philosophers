/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:38:16 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/05 12:55:02 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philo *philo, int eat_time)
{
	pthread_mutex_lock(philo->fork_right);
	info_msg(get_time(), philo->id, FORK_MESSAGE);
	printf("Fork number: %p\n", philo->fork_right);
	pthread_mutex_lock(philo->fork_left);
	printf("Fork number: %p\n", philo->fork_left);
	info_msg(get_time(), philo->id, FORK_MESSAGE);
	philo->time_last_eat = get_time();
	info_msg(philo->time_last_eat, philo->id, EAT_MESSAGE);
	usleep(eat_time * 1000);
	//pthread_mutex_unlock(philo->fork_right);
	//pthread_mutex_unlock(philo->fork_left);
}

static void	philo_sleep(t_philo *philo, int sleep_time)
{
	info_msg(get_time(), philo->id, SLEEP_MESSAGE);
	usleep(sleep_time * 1000);
}

static void	philo_think(t_philo *philo)
{
	info_msg(get_time(), philo->id, THINK_MESSAGE);
}

void	*philo_main(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	philo->time_last_eat = get_time();
	philo_eat(philo, 100);
	philo_sleep(philo, 100);
	philo_think(philo);
	return (NULL);
}
