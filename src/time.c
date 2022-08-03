/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:17:27 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/03 11:04:58 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	get_time(void)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return (time);
}

int	get_time_diff(t_time t1, t_time t2)
{
	int	diff;

	diff = ft_abs(t1.tv_sec - t2.tv_sec) * SEC_TO_USEC;
	diff += ft_abs(t1.tv_usec - t2.tv_usec);
	return (diff);
}
