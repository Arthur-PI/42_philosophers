/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:33:44 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/10 14:08:24 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo_infos *infos, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < infos->nb_philo)
		pthread_mutex_destroy(infos->forks + i++);
	pthread_mutex_destroy(&infos->over_mutex);
	pthread_mutex_destroy(&infos->eat_times_mutex);
	free(infos->forks);
	if (philo)
		free(philo);
}

int	main(int ac, char **av)
{
	int				err;
	t_philo			*philos;
	t_philo_infos	infos;

	if (ac < 5 || ac > 6)
		return (usage(av[0]));
	err = parse_args(av + 1, &infos);
	if (err != ALL_GOOD)
		return (error_msg(err));
	err = init_philosophers(&infos, &philos);
	if (err != ALL_GOOD)
	{
		free_all(&infos, NULL);
		return (error_msg(err));
	}
	err = init_thread(&infos, philos);
	if (err != ALL_GOOD)
	{
		free_all(&infos, philos);
		return (error_msg(err));
	}
	free_all(&infos, philos);
	return (0);
}
