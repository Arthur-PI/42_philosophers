/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:33:44 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 17:35:25 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_semaphores(t_philo_infos *infos)
{
	sem_close(infos->forks);
	sem_close(infos->write_sem);
	sem_close(infos->over_sem);
	sem_close(infos->eat_times);
}

int	main(int ac, char **av)
{
	t_philo_infos	infos;

	if (ac < 5 || ac > 6)
		return (usage(av[0]));
	parse_args(av + 1, &infos);
	start_philos(&infos);
	destroy_semaphores(&infos);
	return (0);
}
