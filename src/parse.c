/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:19:24 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/03 09:56:02 by apigeon          ###   ########.fr       */
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
	*err = ALL_GOOD;
	return (n);
}

int	parse_args(char **args, t_philo_infos *infos)
{
	int	i;
	int	err[5];

	infos->nb_philo = custom_atoi(args[0], &err[0]);
	infos->time_to_die = custom_atoi(args[1], &err[1]);
	infos->time_to_eat = custom_atoi(args[2], &err[2]);
	infos->time_to_sleep = custom_atoi(args[3], &err[3]);
	err[4] = ALL_GOOD;
	if (args[4])
		infos->nb_eat = custom_atoi(args[4], &err[4]);
	i = 0;
	while (i < 5)
		if (err[i++] == ERROR)
			return (PARSE_ERROR);
	return (ALL_GOOD);
}
