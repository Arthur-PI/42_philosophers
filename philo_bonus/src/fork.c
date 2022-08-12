/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:09:33 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/12 15:32:47 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(int philo_id, int cid, t_philo_infos *infos)
{
	int	status;

	(void)infos;
	printf("Je suis le Philo %d !\n", philo_id);
	if (cid == 0)
		exit(1);
	waitpid(cid, &status, 0);
	exit(1);
}

void	start_philos(t_philo_infos *infos)
{
	int	i;
	int	cid;
	int	status;

	i = 0;
	cid = 0;
	while (cid == 0 && i++ < infos->nb_philo)
		cid = fork();
	if (i > 1)
		philo_routine(i - 1, cid, infos);
	waitpid(cid, &status, 0);
}
