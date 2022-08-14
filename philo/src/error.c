/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:47:58 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/14 11:51:57 by apigeon          ###   ########.fr       */
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

	if (code == PARSE_ERROR)
		s = "Error: something is wrong with the arguments";
	else if (code == PHILO_MALLOC_ERROR)
		s = "Error: could not allocate memory for the philosophers";
	else if (code == FORK_MALLOC_ERROR)
		s = "Error: could not allocate memory for the forks";
	else if (code == THREAD_INIT_ERROR)
		s = "Error: could not initalize the threads";
	else if (code == MUTEX_INIT_ERROR)
		s = "Error: could not initialize the mutex";
	else
		s = "An error occured during the program";
	printf("%s\n", s);
	return (code);
}
