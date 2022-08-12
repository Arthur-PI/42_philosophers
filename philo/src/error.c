/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:47:58 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/12 15:04:06 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	usage(const char *p_name)
{
	printf("Usage: %s nb_philo time_to_die time_to_eat", p_name);
	printf(" time_to_sleep [nb_times_must_eat]\n");
	return (1);
}

int	error_msg(int code)
{
	char	*s;
	
	if (code == INVALID_ARG_ERROR)
		s = "Error: invalid arguments";
	else
		s = "An error occured during the program";
	printf("%s. code=%d\n", s, code);
	return (code);
}
