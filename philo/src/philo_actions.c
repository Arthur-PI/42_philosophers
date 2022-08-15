/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:38:16 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/15 10:51:48 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philo *philo, t_philo_infos *infos)
{
	pthread_mutex_lock(philo->fork_right);
	info_msg(get_time(infos->start_time), philo, FORK_MESSAGE);
	if (!philo->fork_left)
	{
		ft_usleep(infos->time_to_die * 2, infos);
		return ;
	}
	pthread_mutex_lock(philo->fork_left);
	info_msg(get_time(infos->start_time), philo, FORK_MESSAGE);
	info_msg(get_time(infos->start_time), philo, EAT_MESSAGE);
	if (!someone_died(infos))
	{
		philo->nb_eat++;
		pthread_mutex_lock(&infos->eat_times_mutex);
		if (philo->nb_eat == infos->must_eat_times)
			infos->eat_times++;
		pthread_mutex_unlock(&infos->eat_times_mutex);
	}
	philo->time_last_eat = get_time(infos->start_time);
	ft_usleep(infos->time_to_eat, infos);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

static void	philo_sleep(t_philo *philo, t_philo_infos *infos)
{
	info_msg(get_time(infos->start_time), philo, SLEEP_MESSAGE);
	ft_usleep(infos->time_to_sleep, infos);
}

static void	philo_think(t_philo *philo, t_philo_infos *infos)
{
	info_msg(get_time(infos->start_time), philo, THINK_MESSAGE);
}

static void	*death_main(void *arg)
{
	long			death_time;
	t_philo			*philo;
	t_philo_infos	*infos;

	philo = (t_philo *)arg;
	infos = philo->infos;
	ft_usleep(infos->time_to_die + 1, infos);
	pthread_mutex_lock(&infos->over_mutex);
	death_time = get_time(infos->start_time);
	if (!infos->over && death_time - philo->time_last_eat >= infos->time_to_die)
	{
		infos->over = TRUE;
		pthread_mutex_unlock(&infos->over_mutex);
		printf(INFO_MSG, death_time, philo->id, DIE_MESSAGE);
	}
	else
		pthread_mutex_unlock(&infos->over_mutex);
	return (NULL);
}

void	*philo_main(void *arg)
{
	t_philo			*philo;
	t_philo_infos	*infos;
	pthread_t		die_thread;

	philo = (t_philo *)arg;
	infos = philo->infos;
	philo->time_last_eat = get_time(infos->start_time);
	if (philo->id % 2 == 0)
		ft_usleep(infos->time_to_eat / 10, infos);
	while (!someone_died(infos))
	{
		pthread_create(&die_thread, NULL, &death_main, arg);
		pthread_detach(die_thread);
		philo_eat(philo, infos);
		check_max_eat(infos);
		philo_sleep(philo, infos);
		philo_think(philo, infos);
	}
	usleep(10000);
	return (NULL);
}
