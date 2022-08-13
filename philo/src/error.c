/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:47:58 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 13:37:29 by apigeon          ###   ########.fr       */
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
	
	s = "An error occured during the program";
	printf("%s. code=%d\n", s, code);
	return (code);
}
