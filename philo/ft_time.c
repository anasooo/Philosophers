/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 06:25:12 by asodor            #+#    #+#             */
/*   Updated: 2024/12/03 13:51:58 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

unsigned long	ft_get_time(void)
{
    struct timeval	time;

    gettimeofday(&time, NULL);
    return ((unsigned long)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}
