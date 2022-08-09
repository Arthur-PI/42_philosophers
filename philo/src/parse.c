/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:19:24 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/09 14:06:46 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	custom_atoi(char *s, int *err)
{
	int		i;
	int		sign;
	long	n;

	*err = ERROR;
	if (!s)
		return (0);
	i = 0;
	sign = get_sign(s[i]);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	n = 0;
	while (ft_isdigit(s[i]) && i < 11)
		n = (n * 10) + (s[i++] - '0');
	n *= sign;
	if (s[i] != 0 || i == 0 || n > INT_MAX || n < INT_MIN)
		return (0);
	if (n >= 0)
		*err = ALL_GOOD;
	return (n);
}

t_fork	*get_forks(int nb_forks)
{
	int		i;
	t_fork	*forks;

	forks = malloc(nb_forks * sizeof(*forks));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb_forks)
	{
		if (pthread_mutex_init(&forks[i], NULL) == -1)
		{
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

int	parse_args(char **args, t_philo_infos *infos)
{
	int	i;
	int	err[5];

	infos->nb_philo = custom_atoi(args[0], &err[0]);
	infos->time_to_die = custom_atoi(args[1], &err[1]);
	infos->time_to_eat = custom_atoi(args[2], &err[2]);
	infos->time_to_sleep = custom_atoi(args[3], &err[3]);
	infos->over = FALSE;
	infos->state_mutex = malloc(sizeof(*infos->state_mutex));
	if (!infos->state_mutex || pthread_mutex_init(infos->state_mutex, NULL) == -1)
		return (MUTEX_INIT_ERROR);
	err[4] = ALL_GOOD;
	if (args[4])
		infos->nb_eat = custom_atoi(args[4], &err[4]);
	i = 0;
	while (i < 5)
		if (err[i++] == ERROR)
			return (PARSE_ERROR);
	infos->forks = get_forks(infos->nb_philo);
	if (!infos->forks)
		return (FORK_MALLOC_ERROR);
	return (ALL_GOOD);
}
