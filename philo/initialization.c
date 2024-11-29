/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 06:11:49 by asodor            #+#    #+#             */
/*   Updated: 2024/11/29 05:07:05 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_set_philo(t_process *process, t_philo *philo, t_fork **forks, long i)
{
    philo->id = i + 1;
    philo->process = process;
    philo->alive = true;
    philo->l_fork = forks[i];
    philo->r_fork = forks[(i + 1) % process->n_philos];
}

static t_philo **init_philos(t_process *process, t_fork **forks)
{
    t_philo **philos;
    long    i;
    
    philos = (t_philo **)malloc(sizeof(t_philo *) * process->n_philos);
    if (!philos)
        return (NULL);
    i = 0;
    while (i < process->n_philos)
    {
        philos[i] = (t_philo *)malloc(sizeof(t_philo));
        if (!philos[i])
            return (ft_free_philos(philos, i), NULL);
        ft_set_philo(process, philos[i], forks, i);
        if (pthread_mutex_init(&philos[i]->mutex, NULL))
            return (ft_free_philos(philos, i), NULL);
        i++;
    }
    return (philos);
}

static t_fork **init_forks(int n_philos)
{
    t_fork  **forks;
    long     i;
    
    forks = (t_fork **)malloc(sizeof(t_fork *) * n_philos);
    if (!forks)
        return (NULL);
    i = 0;
    while (i < n_philos)
    {
        forks[i] = (t_fork *)malloc(sizeof(t_fork));
        if (!forks[i])
            return (ft_free_forks(forks, i), NULL);
        forks[i]->id = i;
        if (pthread_mutex_init(&forks[i]->mutex, NULL))
            return (ft_free_forks(forks, i), NULL);
        i++;
    }
    return (forks);
}

static bool init_process(t_process *process, t_fork **forks, t_philo **philos)
{   process->ready = false;
    process->philo_died = false;
    process->err = false;
    process->finished = 0;
    process->forks = forks;
    process->philos = philos;
    if (pthread_mutex_init(&process->mutex, NULL))
        return (free(process),false);
    if (pthread_mutex_init(&process->print_mutex, NULL))
        return (free(process),false);
    return (true);
}

void    ft_initialization(t_process *process, t_fork **forks, t_philo **philos)
{
    bool p;
    
    forks = init_forks(process->n_philos);
    if (!forks)
    {
        ft_putendl_fd("Forks initialization failed!\n", STDERR_FILENO);
        return (free(process));
    }
    philos = init_philos(process, forks);
    if (!philos)
    {
        ft_putendl_fd("Philos initialization failed!\n", STDERR_FILENO);
        return (free(process));
    }
    p = init_process(process, forks, philos);
    if (!p)
        return (ft_putendl_fd("Process initialization failed!\n", STDERR_FILENO));
}


