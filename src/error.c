/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:47:58 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/03 09:48:20 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	usage(const char *p_name)
{
	printf("Usage: %s nb_philo time_to_die time_to_eat", p_name);
	printf(" time_to_sleep [nb_times_must_eat]\n");
	return (1);
}

int	error_msg(const char *msg, int code)
{
	printf("%s\n", msg);
	return (code);
}
