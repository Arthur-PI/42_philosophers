/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:19:24 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 13:02:18 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	custom_atoi(char *s)
{
	int		i;
	long	n;

	i = 0;
	if (!s || s[i] == '-')
		exit(error_msg(INVALID_ARG_ERROR));
	if (s[i] == '+')
		i++;
	if (!s[i])
		exit(error_msg(INVALID_ARG_ERROR));
	n = 0;
	while (ft_isdigit(s[i]) && i < 11)
		n = (n * 10) + (s[i++] - '0');
	if (s[i] != 0 || i == 0 || n > INT_MAX || n == 0)
		exit(error_msg(INVALID_ARG_ERROR));
	return (n);
}

void	parse_args(char **args, t_philo_infos *infos)
{
	infos->nb_philo = custom_atoi(args[0]);
	infos->time_to_die = custom_atoi(args[1]);
	infos->time_to_eat = custom_atoi(args[2]);
	infos->time_to_sleep = custom_atoi(args[3]);
	infos->over = FALSE;
	sem_init(&infos->over, 0, 1);
	sem_init(&infos->forks, 0, infos->nb_philo);
	sem_init(&infos->over, 0, 1);
	infos->must_eat_times = -1;
	if (args[4])
		infos->must_eat_times = custom_atoi(args[4]);
}
