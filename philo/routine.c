/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:56 by asodor            #+#    #+#             */
/*   Updated: 2024/12/03 17:25:51 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	all_is_ready(t_process *process)
{
    int is_ready;
    
    is_ready = 0;
    while (!is_ready)
    {
        // mutex lock
        is_ready = process->ready;
    }
    return (true);
}

bool	take_r_fork(t_philo *philo, t_process *process)
{   
    if (process->err || process->philo_died)
		return (false);
	ft_print(philo, 'f');
	return (true);
}

bool	take_l_fork(t_philo *philo, t_process *process)
{
    if (process->err || process->philo_died)
        return (false);
    ft_print(philo, 'f');
    return (true);
}

static bool ft_take_forks(t_process *process, t_philo *philo)
{
    if (philo->id % 2 == 0)
        return (take_r_fork(philo, process) && take_l_fork(philo, process));
    else
        return (take_l_fork(philo, process) && take_r_fork(philo, process));
}

static bool	simulation(t_process *process, t_philo *philo)
{
    long m;
    
    if (philo->id % 2)
        usleep(10);
    m = 0;
    while (m < process->n_meals || process->n_meals == -1)
    {
        if (!ft_take_forks(process, philo))
            return (false);
        if (!ft_eat(process, philo))
            return (false);
    }
    
}

void	*ft_routine(void *data)
{
    t_philo	*philo;
    t_process    *process;

    philo = (t_philo *)data;
    process = philo->process;
    
    //wait for all threads to be ready
    if (!all_is_ready(process))
        return (NULL);
    if (!simulation(process, philo))
        return (NULL);
    
    return (NULL);
}