/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:34:37 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/09 14:07:14 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "color.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define ALL_GOOD 0
# define ERROR 1
# define PARSE_ERROR 2
# define PHILO_MALLOC_ERROR 3
# define FORK_MALLOC_ERROR 4
# define THREAD_INIT_ERROR 5
# define MUTEX_INIT_ERROR 6

# define DEBUG_MODE 0

# define DEAD 1
# define ALIVE 0
# define OVER 2

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define SEC_TO_USEC 1000000

# define MS_MULTIPLIER 1000

# ifndef T_BOOL_H
#  define TRUE 1
#  define FALSE 0
# endif

# define FORK_MESSAGE	WHITE "has taken a fork" RESET
# define EAT_MESSAGE	GREEN "is eating" RESET
# define SLEEP_MESSAGE	BLUE "is sleeping" RESET
# define THINK_MESSAGE	YELLOW "is thinking" RESET
# define DIE_MESSAGE	RED "died" RESET

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_fork;


typedef struct s_philo_infos
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				over;
	long			start_time;
	t_fork			*forks;
	pthread_mutex_t	*state_mutex;
}				t_philo_infos;

typedef struct s_philo
{
	int				id;
	long			time_last_eat;
	t_fork			*fork_left;
	t_fork			*fork_right;
	t_philo_infos	*infos;
}				t_philo;

typedef struct s_thread_args
{
	t_philo			*philo;
	t_philo_infos	*infos;
}				t_thread_args;

int		parse_args(char **args, t_philo_infos *infos);
int		ft_abs(int n);
int		ft_isdigit(int c);
int		usage(const char *p_name);
int		error_msg(int code);
int		init_thread(t_philo_infos *infos, t_philo *philos);
int		init_philosophers(t_philo_infos *infos, t_philo **philos_ptr);
void	print_philo(int nb_philo, t_philo *philos);
long	get_time(long start);
long	get_time_diff(long t1, long t2);
void	*philo_main(void *args);
void	info_msg(long time, t_philo *philo, char *msg);

#endif
