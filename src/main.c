/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:33:44 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/05 12:50:06 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int				err;
	t_philo			*philosophers;
	t_philo_infos	philo_infos;

	if (ac < 5 || ac > 6)
		return (usage(av[0]));
	err = parse_args(av + 1, &philo_infos);
	if (err != ALL_GOOD)
		return (error_msg(err));
	err = init_philosophers(philo_infos.nb_philo, &philosophers);
	if (err != ALL_GOOD)
		return (error_msg(err));
	print_philo(philo_infos.nb_philo, philosophers);
	err = init_thread(philo_infos, philosophers);
	if (err != ALL_GOOD)
	{
		destroy_philosophers(philo_infos.nb_philo, philosophers);
		return (error_msg(err));
	}
	destroy_philosophers(philo_infos.nb_philo, philosophers);
	return (0);
}
