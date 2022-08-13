/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:19:24 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 14:55:09 by apigeon          ###   ########.fr       */
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

void	init_semaphore(t_philo_infos *infos)
{
	infos->forks = sem_open(SEM_FORKS, O_CREAT, 664, infos->nb_philo);
	sem_unlink(SEM_FORKS);
	infos->over_sem = sem_open(SEM_OVER, O_CREAT, 664, 0);
	sem_unlink(SEM_OVER);
	infos->eat_times = sem_open(SEM_EAT_TIMES, O_CREAT, 664, 1);
	sem_unlink(SEM_EAT_TIMES);
	infos->write_sem = sem_open(SEM_WRITE, O_CREAT, 664, 1);
	sem_unlink(SEM_WRITE);
	if (infos->forks == SEM_FAILED || infos->over_sem == SEM_FAILED \
			|| infos->eat_times == SEM_FAILED || infos->write_sem == SEM_FAILED)
	{
		destroy_semaphores(infos);
		exit(error_msg(SEM_INIT_ERROR));
	}
}

void	parse_args(char **args, t_philo_infos *infos)
{
	infos->nb_philo = custom_atoi(args[0]);
	infos->time_to_die = custom_atoi(args[1]);
	infos->time_to_eat = custom_atoi(args[2]);
	infos->time_to_sleep = custom_atoi(args[3]);
	infos->must_eat_times = -1;
	init_semaphore(infos);
	if (args[4])
		infos->must_eat_times = custom_atoi(args[4]);
}
