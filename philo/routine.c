/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:56 by asodor            #+#    #+#             */
/*   Updated: 2024/12/18 20:05:00 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	all_is_ready(t_process *process)
{
    int is_ready;
    
    is_ready = 0;
    while (!is_ready)
    {
        is_ready = process->ready;
    }
}

void ft_eat(t_process *process, t_philo *philo)
{
    if (ft_check_philo_died(process, philo) != 0)
        return (NULL);
    set_philo_last_eat(philo);
    ft_print_eating(philo);
    if (process->time->to_eat > process->time->to_die)
        ft_usleep(process->time->to_die);
    else
        ft_usleep(process->time->to_eat);
}
void ft_sleep(t_process *process, t_philo *philo)
{
    if (process->philo_died)
        return (NULL);
    ft_print_sleeping(philo);
    if (process->time->to_sleep > process->time->to_die)
        ft_usleep(process->time->to_die);
    else
        ft_usleep(process->time->to_sleep);
}
void ft_think(t_process *process, t_philo *philo)
{
    if (process->philo_died)
        return (NULL);
    ft_print_thinking(philo);
    ft_usleep(1);
}

static void	simulation(t_process *process, t_philo *philo)
{
    long m;
    
    if (philo->id % 2)
        usleep(10);
    m = 0;
    while (m < process->number_of_meals || process->number_of_meals == -1)
    {
        ft_take_forks(process, philo);
        ft_eat(process, philo);
        m++;
        ft_sleep(process, philo);
        ft_think(process, philo);
    }
}

void	*ft_routine(void *data)
{
    t_philo	*philo;
    t_process    *process;

    philo = (t_philo *)data;
    process = philo->process;
    
    all_is_ready(process);
    simulation(process, philo);
    ft_set_philo_finished(philo);
    ft_update_process_state(process);   
    return (NULL);
}