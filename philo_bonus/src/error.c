/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:40:32 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 17:35:02 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	usage(const char *prog_name)
{
	printf("Usage: %s nb_philo time_to_die time_to_eat time_to_sleep" \
			"[nb_times_must_eat]\n", prog_name);
	return (1);
}

int	error_msg(int code)
{
	char	*s;

	if (code == INVALID_ARG_ERROR)
		s = "Error: invalid arguments";
	else if (code == SEM_INIT_ERROR)
		s = "Error: could not initialize the semaphores";
	else if (code == MALLOC_ERROR)
		s = "Error: could not allocate memory with malloc";
	else
		s = "An error occured during the program";
	printf("%s\n", s);
	return (code);
}
