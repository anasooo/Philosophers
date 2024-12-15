/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:56 by asodor            #+#    #+#             */
/*   Updated: 2024/12/15 03:31:42 by asodor           ###   ########.fr       */
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

bool ft_eat(t_process *process, t_philo *philo)
{
    if (process->err || process->philo_died)
        return (false);
    set_philo_last_eat(philo);
    //need to check for this philo died ?
    ft_print_eating(philo);
    if (process->time->to_eat > process->time->to_die)
        ft_usleep(process->time->to_die);
    else
        ft_usleep(process->time->to_eat);
    return (true);
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
        if (!ft_put_forks(process, philo))
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