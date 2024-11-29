/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 06:25:12 by asodor            #+#    #+#             */
/*   Updated: 2024/11/29 09:36:58 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

unsigned long	ft_get_time(void)
{
    struct timeval	time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_timer(t_process *process)
{
    unsigned long	start;

    start = ft_get_time();
    while (ft_get_time() - start < process->time->to_die)
        usleep(100);
}
