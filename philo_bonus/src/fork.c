/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:09:33 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 14:14:39 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, int id, t_philo_infos *infos)
{
	philo->id = id;
	philo->nb_eat = 0;
	philo->last_eat_time = get_time(infos->start_time);
	philo->infos = infos;
}

void	*death_checker(void *arg)
{
	long			death_time;
	t_philo			*philo;
	t_philo_infos	*infos;

	philo = (t_philo *)arg;
	infos = philo->infos;
	ft_usleep(infos->time_to_die, infos);
	death_time = get_time(infos->start_time);
	sem_wait(&infos->over_sem);
	if (!infos->over && death_time - philo->last_eat_time >= infos->time_to_die)
	{
		infos->over = TRUE;
		sem_post(&infos->over_sem);
		printf(INFO_MSG, death_time, philo->id, DIE_MESSAGE);
	}
	else
		sem_post(&infos->over_sem);
	return (NULL);
}

void	philo_routine(int philo_id, int cid, t_philo_infos *infos)
{
	int			status;
	t_philo		philo;
	pthread_t	death_thread;

	init_philo(&philo, philo_id, infos);
	while (!is_someone_dead(infos))
	{
		pthread_create(&death_thread, NULL, &death_checker, &philo);
		pthread_detach(death_thread);
		philo_eat(&philo, infos);
		philo_sleep(&philo, infos);
		philo_think(&philo, infos);
	}
	usleep(1000);
	if (cid == 0)
		exit(1);
	waitpid(cid, &status, 0);
	exit(1);
}

void	start_philos(t_philo_infos *infos)
{
	int	i;
	int	cid;
	int	status;

	i = 0;
	cid = 0;
	infos->start_time = get_time(0);
	while (cid == 0 && i++ < infos->nb_philo)
		cid = fork();
	if (i > 1)
		philo_routine(i - 1, cid, infos);
	waitpid(cid, &status, 0);
}
