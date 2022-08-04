/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:22:32 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/05 00:28:55 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philosophers(int nb_philo, t_philo *philos)
{
	int	i;
	
	i = 0;
	while (i < nb_philo)
	{
		if (philos[i].id == 0)
			break ;
		pthread_mutex_destroy(&philos[i].fork_right);
		i++;
	}
	free(philos);
}

t_philo	get_philo(int id, t_fork left_fork)
{
	t_philo philo;

	philo.id = id;
	philo.fork_left = left_fork;
	if (pthread_mutex_init(&philo.fork_right, NULL))
		philo.id = 0;
	return (philo);
}

int	init_philosophers(int nb_philo, t_philo **philos_ptr)
{
	int		i;
	t_fork	last_fork;
	t_philo	*philos;

	philos = malloc(nb_philo * sizeof(*philos));
	if (!philos)
		return (PHILO_MALLOC_ERROR);
	i = 0;
	while (i < nb_philo)
	{
		philos[i] = get_philo(i + 1, last_fork);
		if (philos[i].id == 0)
		{
			destroy_philosophers(nb_philo, philos);
			return (FORK_MALLOC_ERROR);
		}
		last_fork = philos[i].fork_right;
		i++;
	}
	if (nb_philo > 1)
		philos[0].fork_left = last_fork;
	*philos_ptr = philos;
	return (ALL_GOOD);
}

void	print_philo(int nb_philo, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		printf("Philo %d\n", philos[i].id);
		i++;
	}
}
