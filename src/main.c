/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:33:44 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/03 00:57:58 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	usage(const char *p_name)
{
	printf("Usage: %s nb_philo time_to_die time_to_eat", p_name);
	printf(" time_to_sleep [nb_times_must_eat]\n");
	return (1);
}

static int	error_msg(const char *msg, int code)
{
	printf("%s\n", msg);
	return (code);
}

int	main(int ac, char **av)
{
	t_philo_infos	infos;

	if (ac < 5 || ac > 6)
		return (usage(av[0]));
	if (parse_args(av + 1, &infos) == PARSE_ERROR)
		return (error_msg("Error while parsing the arguments", 2));
	printf("This is Philosophers\n");
	return (0);
}
