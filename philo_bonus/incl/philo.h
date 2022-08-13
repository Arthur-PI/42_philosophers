/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:34:37 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/13 17:37:30 by apigeon          ###   ########.fr       */
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
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>

# define ALL_GOOD 0
# define ERROR 1
# define PARSE_ERROR 2
# define PHILO_MALLOC_ERROR 3
# define FORK_MALLOC_ERROR 4
# define THREAD_INIT_ERROR 5
# define SEM_INIT_ERROR 6
# define INVALID_ARG_ERROR 7
# define MALLOC_ERROR 8

# define DEAD 1
# define ALIVE 0
# define OVER 2

# define SEM_FORKS "forks"
# define SEM_OVER "over_sem"
# define SEM_EAT_TIMES "eat_times"
# define SEM_WRITE "write"

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

typedef struct timeval	t_time;

typedef struct s_philo_infos
{
	int		nb_philo;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	long	start_time;
	int		must_eat_times;
	int		over;
	int		*philo_pid;
	sem_t	*over_sem;
	sem_t	*forks;
	sem_t	*eat_times;
	sem_t	*write_sem;
}				t_philo_infos;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	long			last_eat_time;
	t_philo_infos	*infos;
}				t_philo;

int		ft_isdigit(char c);
int		error_msg(int code);
int		usage(const char *p_name);
void	parse_args(char **args, t_philo_infos *infos);
int		start_philos(t_philo_infos *infos);
void	info_msg(long time, t_philo *philo, char *msg);
void	ft_usleep(int ms);
long	get_time(long start_time);
int		is_someone_dead(t_philo_infos *infos);
void	philo_eat(t_philo *philo, t_philo_infos *infos);
void	philo_sleep(t_philo *philo, t_philo_infos *infos);
void	philo_think(t_philo *philo, t_philo_infos *infos);
void	destroy_semaphores(t_philo_infos *infos);

#endif
