/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 02:08:23 by asodor            #+#    #+#             */
/*   Updated: 2024/12/03 13:58:04 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool ft_create_threads(t_process *process)
{
    long i;
    
    i = 0;
    while (i < process->n_philos)
    {
        if (pthread_create(&process->philos[i]->thread, NULL, ft_routine, (void *)process->philos[i]))
            return (ft_putendl_fd("Error: Failed to create thread", STDERR_FILENO), false);
        i++;
    }
    return (true);
}
static void ft_join_threads(t_process *process)
{
    long i;
    
    i = 0;
    while (i < process->n_philos)
    {
        if (pthread_join(process->philos[i]->thread, NULL))
            return (ft_putendl_fd("Error: Failed to join thread", STDERR_FILENO));
        i++;
    }
}
void ft_threads(t_process *process)
{
    if (!ft_create_threads(process))
        return ;
    ft_get_time();
    set_ready(process);
    return (ft_join_threads(process));
}