/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:58:24 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 14:05:35 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	info_msg(long time, t_philo *philo, char *msg)
{
	sem_wait(&philo->infos->over_sem);
	if (!philo->infos->over)
		printf(INFO_MSG, time, philo->id, msg);
	sem_post(&philo->infos->over_sem);
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
	while (!is_someone_dead(infos) && get_time(start) < ms)
		usleep(offset);
}
