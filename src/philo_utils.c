/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:22:32 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/07 14:38:18 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mod_number(int n, int mod)
{
	if (n < 0)
		return (n + mod);
	return (n % mod);
}

t_philo	get_philo(int id, t_philo_infos *infos)
{
	t_philo	philo;

	philo.id = id;
	philo.fork_right = infos->forks + (id - 1);
	philo.fork_left = infos->forks + mod_number(id - 2, infos->nb_philo);
	philo.infos = infos;
	return (philo);
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
