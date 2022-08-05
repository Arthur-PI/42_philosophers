/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:22:32 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/05 12:52:11 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philosophers(int nb_philo, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (philos[i].fork_right != NULL)
			pthread_mutex_destroy(philos[i].fork_right);
		i++;
	}
	free(philos);
}

t_fork	*get_fork(void)
{
	t_fork	*fork;

	fork = malloc(sizeof(fork));
	if (!fork)
		return (NULL);
	if (pthread_mutex_init(fork, NULL) == -1)
	{
		free(fork);
		return (NULL);
	}
	return (fork);
}

t_philo	get_philo(int id, t_fork *left_fork)
{
	t_philo	philo;

	philo.id = id;
	philo.fork_left = left_fork;
	philo.fork_right = get_fork();
	return (philo);
}

int	init_philosophers(int nb_philo, t_philo **philos_ptr)
{
	int		i;
	t_fork	*last_fork;
	t_philo	*philos;

	philos = malloc(nb_philo * sizeof(*philos));
	if (!philos)
		return (PHILO_MALLOC_ERROR);
	i = 0;
	last_fork = NULL;
	while (i < nb_philo)
	{
		philos[i] = get_philo(i + 1, last_fork);
		if (philos[i].fork_right == NULL)
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
		printf("Philo %d:\n- Fork Left:  %p\n- Fork Right: %p\n\n", philos[i].id, philos[i].fork_left, philos[i].fork_right);
		i++;
	}
}
