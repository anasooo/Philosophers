/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:32:13 by asodor            #+#    #+#             */
/*   Updated: 2024/12/22 18:14:18 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_r_fork(t_philo *philo, t_process *process)
{
	if (ft_check_philo_died(process) != 0)
		return (0);
	pthread_mutex_lock(&philo->r_fork->mutex);
	if (ft_check_philo_died(process) != 0)
	{
		pthread_mutex_unlock(&philo->r_fork->mutex);
		if (philo->id % 2 != 0)
			pthread_mutex_unlock(&philo->l_fork->mutex);
		return (0);
	}
	ft_print_fork(philo);
	return (1);
}

int	take_l_fork(t_philo *philo, t_process *process)
{
	if (ft_check_philo_died(process) != 0)
		return (0);
	pthread_mutex_lock(&philo->l_fork->mutex);
	if (ft_check_philo_died(process) != 0)
	{
		pthread_mutex_unlock(&philo->l_fork->mutex);
		if (philo->id % 2 == 0)
			pthread_mutex_unlock(&philo->r_fork->mutex);
		return (0);
	}
	ft_print_fork(philo);
	if (ft_check_number_of_philos(process) == 1)
		ft_set_philo_died(process);
	return (1);
}

int	ft_take_forks(t_process *process, t_philo *philo)
{
	if (philo->id % 2 == 0)
		return (take_r_fork(philo, process) && take_l_fork(philo, process));
	else
		return (take_l_fork(philo, process) && take_r_fork(philo, process));
}

int	ft_put_forks(t_process *process, t_philo *philo)
{
	pthread_mutex_unlock(&philo->l_fork->mutex);
	pthread_mutex_unlock(&philo->r_fork->mutex);
	if (ft_check_philo_died(process) != 0)
		return (0);
	return (1);
}
