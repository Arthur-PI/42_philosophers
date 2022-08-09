/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:38:16 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/08 16:56:09 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
int	is_someone_dead(t_philo_infos *infos)
{
	int	ret;

	//pthread_mutex_lock(&infos->state_mutex);
	ret = infos->over;
	//pthread_mutex_unlock(&infos->state_mutex);
	return (ret);
}

void	game_over(t_philo_infos *infos)
{
	//pthread_mutex_lock(&infos->state_mutex);
	infos->over = TRUE;
	//pthread_mutex_unlock(&infos->state_mutex);
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


void	*philo_main(void *arg)
{
	int				state;
	t_philo			*philo;
	t_philo_infos	*infos;

	philo = (t_philo *) arg;
	infos = philo->infos;
	philo->time_last_eat = get_time(infos->start_time);
	info_msg(get_time(infos->start_time), philo->id, "started");
	return (NULL);
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
*/

int	is_philo_dead(t_philo *philo, t_philo_infos *infos)
{
	if (get_time_diff(get_time(infos->start_time), philo->time_last_eat) >= infos->time_to_die)	
	{
		info_msg(get_time(infos->start_time), philo, DIE_MESSAGE);
		infos->over = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

int	take_fork(t_philo *philo, t_fork *fork)
{
	if (is_philo_dead(philo, philo->infos))
		return (FALSE);
	pthread_mutex_lock(fork);
	info_msg(get_time(philo->infos->start_time), philo, FORK_MESSAGE);
	return (TRUE);
}

int	take_forks(t_philo *philo)
{
	t_fork	*f1;
	t_fork	*f2;
	
	f1 = philo->fork_right;
	f2 = philo->fork_left;
	if (philo->id % 2 == 0)
	{
		f1 = philo->fork_left;
		f2 = philo->fork_right;
	}
	if (!take_fork(philo, f1))
		return (FALSE);
	if (!take_fork(philo, f2))
		return (FALSE);
	return (TRUE);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

int	philo_eat(t_philo *philo, t_philo_infos *infos)
{
	take_forks(philo);
	is_philo_dead(philo, infos);
	philo->time_last_eat = get_time(infos->start_time);
	info_msg(philo->time_last_eat, philo, EAT_MESSAGE);
	usleep(infos->time_to_eat * 1000);
	drop_forks(philo);
	return (ALIVE);
}

static void	philo_sleep(t_philo *philo, int sleep_time)
{
	if (philo->infos->over)
		return ;
	info_msg(get_time(philo->infos->start_time), philo, SLEEP_MESSAGE);
	usleep(sleep_time * 1000);
}

static void	philo_think(t_philo *philo)
{
	if (philo->infos->over)
		return ;
	info_msg(get_time(philo->infos->start_time), philo, THINK_MESSAGE);
}

void	*philo_main(void *arg)
{
	t_philo			*philo;
	t_philo_infos	*infos;

	philo = (t_philo *)arg;
	infos = philo->infos;
	philo->time_last_eat = get_time(infos->start_time);
	while (infos->over == FALSE)
	{
		philo_eat(philo, infos);
		philo_sleep(philo, infos->time_to_sleep);
		philo_think(philo);
	}
	return (NULL);
}
