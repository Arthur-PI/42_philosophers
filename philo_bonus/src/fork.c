/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:09:33 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 17:38:04 by apigeon          ###   ########.fr       */
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

void	*death_monitoring(void *arg)
{
	long			death_time;
	t_philo			*philo;
	t_philo_infos	*infos;

	philo = (t_philo *)arg;
	infos = philo->infos;
	ft_usleep(infos->time_to_die);
	death_time = get_time(infos->start_time);
	if (philo->nb_eat != infos->must_eat_times \
			&& death_time - philo->last_eat_time >= infos->time_to_die)
	{
		sem_post(infos->over_sem);
		sem_wait(infos->write_sem);
		printf(INFO_MSG, death_time, philo->id, DIE_MESSAGE);
	}
	return (NULL);
}

void	philo_routine(int philo_id, t_philo_infos *infos)
{
	t_philo		philo;
	pthread_t	death_thread;

	init_philo(&philo, philo_id, infos);
	if (philo_id % 2 == 0)
		usleep((infos->time_to_eat / 2) * 1000);
	while (philo.nb_eat != infos->must_eat_times)
	{
		pthread_create(&death_thread, NULL, &death_monitoring, &philo);
		pthread_detach(death_thread);
		philo_eat(&philo, infos);
		philo_sleep(&philo, infos);
		philo_think(&philo, infos);
	}
	ft_usleep(infos->time_to_die + 1);
	destroy_semaphores(infos);
	free(infos->philo_pid);
	exit(0);
}

void	*max_eat_monitoring(void *arg)
{
	int				i;
	int				status;
	t_philo_infos	*infos;

	infos = (t_philo_infos *)arg;
	i = 0;
	while (i < infos->nb_philo)
		waitpid(infos->philo_pid[i++], &status, 0);
	sem_post(infos->over_sem);
	return (NULL);
}

int	start_philos(t_philo_infos *infos)
{
	int			i;
	pthread_t	max_eat_thread;

	infos->philo_pid = malloc(sizeof(*infos->philo_pid) * infos->nb_philo);
	if (!infos->philo_pid)
		return (error_msg(MALLOC_ERROR));
	i = 0;
	infos->start_time = get_time(0);
	while (i < infos->nb_philo)
	{
		infos->philo_pid[i] = fork();
		if (infos->philo_pid[i] == 0)
			philo_routine(i + 1, infos);
		i++;
	}
	pthread_create(&max_eat_thread, NULL, &max_eat_monitoring, infos);
	sem_wait(infos->over_sem);
	i = 0;
	while (i < infos->nb_philo)
		kill(infos->philo_pid[i++], SIGKILL);
	pthread_join(max_eat_thread, NULL);
	free(infos->philo_pid);
	return (ALL_GOOD);
}
