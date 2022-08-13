/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:45:01 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 16:43:34 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo, t_philo_infos *infos)
{
	sem_wait(infos->forks);
	info_msg(get_time(infos->start_time), philo, FORK_MESSAGE);
	sem_wait(infos->forks);
	info_msg(get_time(infos->start_time), philo, FORK_MESSAGE);
	philo->last_eat_time = get_time(infos->start_time);
	info_msg(get_time(infos->start_time), philo, EAT_MESSAGE);
	philo->nb_eat++;
	ft_usleep(infos->time_to_eat);
	sem_post(infos->forks);
	sem_post(infos->forks);
}

void	philo_sleep(t_philo *philo, t_philo_infos *infos)
{
	info_msg(get_time(infos->start_time), philo, SLEEP_MESSAGE);
	ft_usleep(infos->time_to_sleep);
}

void	philo_think(t_philo *philo, t_philo_infos *infos)
{
	info_msg(get_time(infos->start_time), philo, THINK_MESSAGE);
}
