/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:50:53 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/08 16:20:08 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (FALSE);
	return (TRUE);
}

void	info_msg(long time, t_philo *philo, char *msg)
{
	if (!philo->infos->over)
		printf("%4ld %d %s\n", time, philo->id, msg);
}
