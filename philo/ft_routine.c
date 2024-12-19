/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:56 by asodor            #+#    #+#             */
/*   Updated: 2024/12/19 15:17:19 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_is_ready(t_process *process)
{
    int is_ready;
    
    is_ready = 0;
    while (!is_ready)
    {
        pthread_mutex_lock(&process->mutex);
        is_ready = process->ready;
        pthread_mutex_unlock(&process->mutex);
    }
}

int ft_eat(t_process *process, t_philo *philo)
{
    if (ft_check_philo_died(process) != 0)
        return (0);
    set_philo_last_eat(philo);
    ft_print_eating(philo);
    if (process->time.to_eat > process->time.to_die)
        ft_usleep(process->time.to_die);
    else
        ft_usleep(process->time.to_eat);
    return (1);
}
int ft_sleep(t_process *process, t_philo *philo)
{
    if (ft_check_philo_died(process) != 0)
        return (0);
    ft_print_sleeping(philo);
    if (process->time.to_sleep > process->time.to_die)
        ft_usleep(process->time.to_die);
    else
        ft_usleep(process->time.to_sleep);
    return (1);
}
int ft_think(t_process *process, t_philo *philo)
{
    if (ft_check_philo_died(process) != 0)
        return (0);
    ft_print_thinking(philo);
    ft_usleep(1);
    return (1);
}

int	simulation(t_process *process, t_philo *philo)
{
    long m;
    
    if (philo->id % 2)
        usleep(10);
    m = 0;
    while (m < process->number_of_meals || process->number_of_meals == -1)
    {
        if (!ft_take_forks(process, philo))
            return (0);
        if (!ft_eat(process, philo))
            return (0);
        if (!ft_put_forks(process, philo))
            return (0);
        m++;
        if (!ft_sleep(process, philo))  
            return (0);
        if (!ft_think(process, philo))
            return (0);
    }
    return (1);
}

void	*ft_routine(void *data)
{
    t_philo	*philo;
    t_process    *process;

    philo = (t_philo *)data;
    process = philo->process;
    
    all_is_ready(process);
    if (!simulation(process, philo))
        return (NULL);
    ft_set_philo_finished(philo);
    ft_update_process_state(process);   
    return (NULL);
}