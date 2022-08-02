/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:19:24 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/03 00:55:44 by apigeon          ###   ########.fr       */
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
	int	err1;
	int	err2;
	int	err3;
	int	err4;

	infos->nb_philo = custom_atoi(args[0], &err1);
	infos->time_to_die = custom_atoi(args[1], &err2);
	infos->time_to_eat = custom_atoi(args[2], &err3);
	infos->time_to_sleep = custom_atoi(args[3], &err4);
	if (err1 == ERROR || err2 == ERROR || err3 == ERROR || err4 == ERROR)
		return (PARSE_ERROR);
	return (ALL_GOOD);
}
