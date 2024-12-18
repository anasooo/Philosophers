/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:32:13 by asodor            #+#    #+#             */
/*   Updated: 2024/12/18 22:01:14 by asodor           ###   ########.fr       */
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
    if (ft_check_philo_died(process) != 0)
    {
        pthread_mutex_unlock(&philo->r_fork->mutex);
        if (philo->id % 2 != 0)
            pthread_mutex_unlock(&philo->l_fork->mutex);
        return (NULL);
    }
	ft_print_fork(philo);
}

void	take_l_fork(t_philo *philo, t_process *process)
{
    if (ft_check_philo_died(process) != 0)
        return (NULL);
    pthread_mutex_lock(&philo->l_fork->mutex);
    if(ft_check_philo_died(process) != 0)
    {
        pthread_mutex_unlock(&philo->l_fork->mutex);
        if (philo->id % 2 == 0)
            pthread_mutex_unlock(&philo->l_fork->mutex);
        return (NULL);
    }
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

void ft_put_forks(t_process *process, t_philo *philo)
{
    pthread_mutex_unlock(&philo->l_fork->mutex);
    pthread_mutex_unlock(&philo->r_fork->mutex);
    if (ft_check_philo_died(process) != 0)
        return (NULL);
}
