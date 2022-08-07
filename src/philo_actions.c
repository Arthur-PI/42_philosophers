/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:38:16 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/07 16:51:51 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_someone_dead(t_philo_infos *infos)
{
	int	ret;

	pthread_mutex_lock(&infos->state_mutex);
	ret = infos->over;
	pthread_mutex_unlock(&infos->state_mutex);
	return (ret);
}

void	game_over(t_philo_infos *infos)
{
	pthread_mutex_lock(&infos->state_mutex);
	infos->over = TRUE;
	pthread_mutex_unlock(&infos->state_mutex);
}

int	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(fork);
	if (is_someone_dead(philo->infos))
		return (FALSE);
	info_msg(get_time(philo->infos->start_time), philo->id, FORK_MESSAGE);
	return (TRUE);
}

int	odd_fork_lock(t_philo *philo)
{
	if (!take_fork(philo, philo->fork_right))
		return (TRUE);
	if (!take_fork(philo, philo->fork_left))
		return (TRUE);
	return (FALSE);
}

int	even_fork_lock(t_philo *philo)
{
	if (!take_fork(philo, philo->fork_left))
		return (TRUE);
	if (!take_fork(philo, philo->fork_right))
		return (TRUE);
	return (FALSE);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

static int	philo_eat(t_philo *philo, int time_to_eat, int time_to_die)
{
	int		err;
	long	eat_time;


	if (philo->id % 2 == 1)
		err = odd_fork_lock(philo);
	else
		err = even_fork_lock(philo);
	eat_time = get_time(philo->infos->start_time);
	if (err || get_time_diff(philo->time_last_eat, eat_time) > time_to_die)
	{
		unlock_forks(philo);
		if (err)
			return (OVER);
		return (DEAD);
	}
	philo->time_last_eat = eat_time;
	info_msg(philo->time_last_eat, philo->id, EAT_MESSAGE);
	usleep(time_to_eat * 1000);
	unlock_forks(philo);
	return (ALIVE);
}

static void	philo_sleep(t_philo *philo, int sleep_time)
{
	if (philo->infos->over)
		return ;
	info_msg(get_time(philo->infos->start_time), philo->id, SLEEP_MESSAGE);
	usleep(sleep_time * 1000);
}

static void	philo_think(t_philo *philo)
{
	if (philo->infos->over)
		return ;
	info_msg(get_time(philo->infos->start_time), philo->id, THINK_MESSAGE);
}

void	*philo_main(void *arg)
{
	int				state;
	t_philo			*philo;
	t_philo_infos	*infos;

	philo = (t_philo *) arg;
	infos = philo->infos;
	philo->time_last_eat = get_time(infos->start_time);
	while (TRUE)
	{
		state = philo_eat(philo, infos->time_to_eat, infos->time_to_die);
		if (state != ALIVE)
		{
			game_over(infos);
			if (state == DEAD)
				info_msg(get_time(infos->start_time), philo->id, DIE_MESSAGE);
			return (NULL);
		}
		philo_sleep(philo, infos->time_to_sleep);
		philo_think(philo);
	}
	return (NULL);
}
