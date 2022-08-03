/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:33:44 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/03 18:24:55 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo			*philosophers;
	t_philo_infos	philo_infos;

	if (ac < 5 || ac > 6)
		return (usage(av[0]));
	if (parse_args(av + 1, &philo_infos) == PARSE_ERROR)
		return (error_msg("Error while parsing the arguments", 2));
	if (init_philosophers(philo_infos.nb_philo, &philosophers) == PHILO_INIT_ERROR)
		return (error_msg("Error while initializing the philophers", 3));
	if (init_thread(philo_infos, philosophers) == THREAD_INIT_ERROR)
	{
		destroy_philosophers(philosophers);
		return (error_msg("Error while initialzing the threads", 4));
	}
	print_philo(philo_infos.nb_philo, philosophers);
	destroy_philosophers(philosophers);
	printf("This is Philosophers\n");
	return (0);
}
