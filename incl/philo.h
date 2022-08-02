/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:34:37 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/03 00:53:55 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define ALL_GOOD 1
# define PARSE_ERROR -2

# define ERROR -1

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# ifndef T_BOOL_H
#  define TRUE 1
#  define FALSE 0
# endif

typedef struct s_philo_infos
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_eat;
}				t_philo_infos;

int	parse_args(char **args, t_philo_infos *infos);
int	ft_isdigit(int c);

#endif