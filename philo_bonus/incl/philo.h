/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:34:37 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/11 16:15:42 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

# define ALL_GOOD 0
# define ERROR 1
# define PARSE_ERROR 2
# define PHILO_MALLOC_ERROR 3
# define FORK_MALLOC_ERROR 4
# define THREAD_INIT_ERROR 5
# define MUTEX_INIT_ERROR 6

# define DEAD 1
# define ALIVE 0
# define OVER 2

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# ifndef T_BOOL_H
#  define TRUE 1
#  define FALSE 0
# endif

# define INFO_MSG "%4ld \033[1;37m%d\033[0m %s\n"

# define FORK_MESSAGE	"has taken a fork"
# define EAT_MESSAGE	"\033[1;32mis eating\033[0m"
# define SLEEP_MESSAGE	"\033[1;34mis sleeping\033[0m"
# define THINK_MESSAGE	"\033[1;33mis thinking\033[0m"
# define DIE_MESSAGE	"\033[1;31mdied\033[0m"

#endif
