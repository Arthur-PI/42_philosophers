/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:33:44 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/30 19:37:53 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	usage(const char *p_name)
{
	printf("Usage: %s number_of_philosophers time_to_die time_to_eat", p_name);
	printf(" time_to_sleep [number_each_philo_must_eat]\n");
	return (1);
}

static int	parse_args(char **args, t_philo_infos *infos)
{
	infos->nb_philo = ft_atoi(args[0]);
	infos->time_to_die = ft_atoi(args[1]);
	infos->time_to_eat = ft_atoi(args[2]);
	infos->time_to_sleep = ft_atoi(args[3]);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo_infos	infos;

	if (ac < 5 || ac > 6)
		return (usage(av[0]));
	if (parse_args(av + 1, &infos) == -1)
	{
		printf("Error while parsing the arguments");
		return (1);
	}
	printf("This is Philosophers\n");
	return (0);
}
