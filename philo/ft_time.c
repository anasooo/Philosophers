/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 06:25:12 by asodor            #+#    #+#             */
/*   Updated: 2024/12/15 03:22:02 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

unsigned long	ft_get_time(void)
{
    struct timeval	time;

    gettimeofday(&time, NULL);
    return ((unsigned long)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}
ft_usleep(unsigned long time)
{
    unsigned long start;

    start = ft_get_time();
    while (ft_get_time() - start < time)
        usleep(60);
    return (0);
}