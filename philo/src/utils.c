/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:50:53 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/10 18:10:26 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (FALSE);
	return (TRUE);
}

void	info_msg(long time, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->infos->over_mutex);
	if (!philo->infos->over)
		printf(INFO_MSG, time, philo->id, msg);
	pthread_mutex_unlock(&philo->infos->over_mutex);
}

void	ft_usleep(int ms, t_philo_infos *infos)
{
	int		offset;
	long	start;

	start = get_time(0);
	offset = 10;
	if (ms < 100)
		offset = ms / 10;
	offset *= 100;
	while (!someone_died(infos) && get_time(start) < ms)
		usleep(offset);
}
