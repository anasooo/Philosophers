/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:56 by asodor            #+#    #+#             */
/*   Updated: 2024/12/03 15:16:25 by asodor           ###   ########.fr       */
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

void	*ft_routine(void *data)
{
    t_philo	*philo;
    t_process    *process;

    philo = (t_philo *)data;
    process = philo->process;
    if (!all_is_ready(process))
        return (NULL);
    
    return (NULL);
}