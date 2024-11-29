/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 02:08:23 by asodor            #+#    #+#             */
/*   Updated: 2024/11/29 05:05:04 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_create_threads(t_process *process)
{
    long i;
    
    i = 0;
    while (i < process->n_philos)
    {
        if (pthread_create(&process->philos[i]->thread, NULL, ft_routine, (void *)process->philos[i]))
            return ;
        i++;
    }
}
static void ft_join_threads(t_process *process)
{
    long i;
    
    i = 0;
    while (i < process->n_philos)
    {
        if (pthread_join(process->philos[i]->thread, NULL))
            return ;
        i++;
    }
}
void ft_threads(t_process *process)
{
    ft_create_threads(process);
    
}