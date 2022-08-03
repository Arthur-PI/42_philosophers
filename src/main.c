/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:33:44 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/03 11:37:23 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_philosophers(t_philo **philos, int code)
{
	(void)philos;
	return code;
}

int	init_philosophers(int nb_philo, t_philo **philos)
{
	int		i;
	t_philo	*philo;

	*philos = malloc(**philos * nb_philo);
	if (!*philos)
		return (PHILO_INIT_ERROR);
	i = 0;
	while (i < nb_philo)
	{
		philo = malloc(*philo);
		if (!philo)
			return (destroy_philosophers(philos, PHILO_INIT_ERROR));
		(*philos)[i] = philo;
		philo->id = i + 1;
		i++;
	}
	return (ALL_GOOD);
}

int	main(int ac, char **av)
{
	t_philo			*philosophers;
	t_philo_infos	philo_infos;

	if (ac < 5 || ac > 6)
		return (usage(av[0]));
	if (parse_args(av + 1, &philo_infos) == PARSE_ERROR)
		return (error_msg("Error while parsing the arguments", 2));
	if (init_philosophers(philo_infos, &philosophers) == PHILO_INIT_ERROR)
		return (error_msg("Error while initializing the philophers", 3));
	if (init_thread(philo_infos, philosophers) == THREAD_INIT_ERROR)
	{
		destroy_philosophers(&philosophers);
		return (error_msg("Error while initialzing the threads", 4));
	}
	printf("This is Philosophers\n");
	return (0);
}
