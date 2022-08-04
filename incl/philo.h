/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:34:37 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/05 00:49:04 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

# define DEBUG_MODE 0

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define SEC_TO_USEC 1000000

# ifndef T_BOOL_H
#  define TRUE 1
#  define FALSE 0
# endif

# define FORK_MESSAGE "has taken a fork"
# define EAT_MESSAGE "is eating"
# define SLEEP_MESSAGE "is sleeping"
# define THINK_MESSAGE "is thinking"

typedef struct timeval t_time;
typedef pthread_mutex_t t_fork;

typedef struct s_philo_infos
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_eat;
}				t_philo_infos;

typedef struct s_philo
{
	int		id;
	t_time	time_last_eat;
	t_fork	fork_left;
	t_fork	fork_right;
}				t_philo;


int		parse_args(char **args, t_philo_infos *infos);
int		ft_abs(int n);
int		ft_isdigit(int c);
int		usage(const char *p_name);
int		error_msg(int code);
int		init_thread(t_philo_infos infos, t_philo *philos);
int		init_philosophers(int nb_philo, t_philo **philos);
void	destroy_philosophers(int nb_philo, t_philo *philos);
void	print_philo(int nb_philo, t_philo *philos);
t_time	get_time(void);

#endif
