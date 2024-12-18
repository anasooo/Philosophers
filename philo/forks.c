/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:32:13 by asodor            #+#    #+#             */
/*   Updated: 2024/12/18 11:37:53 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_check_philo_died(t_process *process)
{
    int died;
    pthread_mutex_lock(&process->mutex);
    died = process->philo_died;
    pthread_mutex_unlock(&process->mutex);
    return (died);
}

void	take_r_fork(t_philo *philo, t_process *process)
{
    if (ft_check_philo_died(process) != 0)
        return (NULL);
    pthread_mutex_lock(&philo->r_fork->mutex);
    if (ft_check_philo_died(process))
    {
        //
    }
	ft_print_fork(philo);
}

void	take_l_fork(t_philo *philo, t_process *process)
{
    if (process->philo_died)
        return (NULL);
    ft_print_fork(philo);
}

void  ft_take_forks(t_process *process, t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        take_r_fork(philo, process);
        take_l_fork(philo, process);
    }else
    {
        take_l_fork(philo, process);
        take_r_fork(philo, process);
    }
}
