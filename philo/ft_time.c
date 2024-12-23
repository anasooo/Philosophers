/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 06:25:12 by asodor            #+#    #+#             */
/*   Updated: 2024/12/23 16:05:52 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_get_time(void)
{
	struct timeval			time;
	static unsigned long	start;

	if (!start)
	{
		gettimeofday(&time, NULL);
		start = (unsigned int)(time.tv_sec * 1000 + time.tv_usec / 1000);
		return (0);
	}
	gettimeofday(&time, NULL);
	return ((unsigned int)(time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
}

int	ft_usleep(unsigned long time)
{
	unsigned long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(60);
	return (0);
}
