/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:50:53 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/05 12:56:46 by apigeon          ###   ########.fr       */
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

void	info_msg(t_time time, int id, char *msg)
{
	printf("%3d %d %s\n", time.tv_usec / 1000, id, msg);
}
