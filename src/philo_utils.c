/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:22:32 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/03 18:25:50 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philosophers(t_philo *philos)
{
	free(philos);
	(void)philos;
}

t_philo	get_philo(int id)
{
	t_philo philo;

	philo.id = id;
	return (philo);
}

int	init_philosophers(int nb_philo, t_philo **philos)
{
	int		i;

	*philos = malloc(nb_philo * sizeof(**philos));
	if (!*philos)
		return (PHILO_INIT_ERROR);
	i = 0;
	while (i < nb_philo)
	{
		(*philos)[i] = get_philo(i + 1);
		i++;
	}
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
