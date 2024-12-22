/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:03:57 by asodor            #+#    #+#             */
/*   Updated: 2024/12/22 17:58:01 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_philo_died(t_process *process)
{
	pthread_mutex_lock(&process->mutex);
	process->philo_died = 1;
	pthread_mutex_unlock(&process->mutex);
}

int	ft_check_philo_died(t_process *process)
{
	int	died;

	pthread_mutex_lock(&process->mutex);
	died = process->philo_died;
	pthread_mutex_unlock(&process->mutex);
	return (died);
}

int	ft_check_philo_finished(t_philo *philo)
{
	int	finished;

	pthread_mutex_lock(&philo->mutex);
	finished = philo->finished;
	pthread_mutex_unlock(&philo->mutex);
	return (finished);
}

int	ft_check_process_finished(t_process *process)
{
	int	finished;

	pthread_mutex_lock(&process->mutex);
	finished = process->finished;
	pthread_mutex_unlock(&process->mutex);
	return (finished);
}

int	ft_check_number_of_philos(t_process *p)
{
	int	nb;

	pthread_mutex_lock(&p->mutex);
	nb = p->number_of_philos;
	pthread_mutex_unlock(&p->mutex);
	return (nb);
}
