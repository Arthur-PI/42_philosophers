/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:33:44 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/07 14:10:42 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		return (error_msg(err));
	err = init_thread(&infos, philos);
	if (err != ALL_GOOD)
	{
		free(philos);
		return (error_msg(err));
	}
	free(philos);
	return (0);
}
