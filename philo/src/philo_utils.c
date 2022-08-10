/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:22:32 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/10 18:28:12 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mod_number(int n, int mod)
{
	if (n < 0)
		return (n + mod);
	return (n % mod);
}

static t_philo	get_philo(int id, t_philo_infos *infos)
{
	t_philo	philo;

	philo.id = id;
	philo.nb_eat = 0;
	philo.fork_right = infos->forks + (id - 1);
	philo.fork_left = NULL;
	if (infos->nb_philo > 1)
		philo.fork_left = infos->forks + mod_number(id - 2, infos->nb_philo);
	philo.infos = infos;
	return (philo);
}

void	check_max_eat(t_philo_infos *infos)
{
	pthread_mutex_lock(&infos->eat_times_mutex);
	if (infos->must_eat_times >= 0 && infos->eat_times == infos->nb_philo)
	{
		pthread_mutex_lock(&infos->over_mutex);
		infos->over = TRUE;
		pthread_mutex_unlock(&infos->over_mutex);
	}
	pthread_mutex_unlock(&infos->eat_times_mutex);
}

int	someone_died(t_philo_infos *infos)
{
	int	ret;

	pthread_mutex_lock(&infos->over_mutex);
	ret = infos->over;
	pthread_mutex_unlock(&infos->over_mutex);
	return (ret);
}

int	init_philosophers(t_philo_infos *infos, t_philo **philos_ptr)
{
	int		i;
	t_philo	*philos;

	philos = malloc(infos->nb_philo * sizeof(*philos));
	if (!philos)
		return (PHILO_MALLOC_ERROR);
	i = 0;
	while (i < infos->nb_philo)
	{
		philos[i] = get_philo(i + 1, infos);
		i++;
	}
	*philos_ptr = philos;
	return (ALL_GOOD);
}
