/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:45:01 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 14:08:33 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_someone_dead(t_philo_infos *infos)
{
	int	 ret;

	sem_wait(&infos->over_sem);
	ret = infos->over;
	sem_post(&infos->over_sem);
	return (ret);
}

void	philo_eat(t_philo *philo, t_philo_infos *infos)
{
	sem_wait(&infos->forks);
	info_msg(get_time(infos->start_time), philo, FORK_MESSAGE);
	sem_wait(&infos->forks);
	info_msg(get_time(infos->start_time), philo, FORK_MESSAGE);
	info_msg(get_time(infos->start_time), philo, EAT_MESSAGE);
	philo->last_eat_time = get_time(infos->start_time);
	ft_usleep(infos->time_to_eat, infos);
	sem_post(&infos->forks);
	sem_post(&infos->forks);
}

void	philo_sleep(t_philo *philo, t_philo_infos *infos)
{
	info_msg(get_time(infos->start_time), philo, SLEEP_MESSAGE);
	ft_usleep(infos->time_to_sleep, infos);
}

void	philo_think(t_philo *philo, t_philo_infos *infos)
{
	info_msg(get_time(infos->start_time), philo, THINK_MESSAGE);
}
