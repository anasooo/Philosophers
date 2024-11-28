/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 07:09:43 by asodor            #+#    #+#             */
/*   Updated: 2024/11/28 07:10:10 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_free_forks(t_fork **forks, long n_philos)
{
    long	i;

    i = 0;
    while (i < n_philos)
    {
        free(forks[i]);
        i++;
    }
    free(forks);
}

void	ft_free_philos(t_philo **philos, long n_philos)
{
    long	i;

    i = 0;
    while (i < n_philos)
    {
        free(philos[i]);
        i++;
    }
    free(philos);
}

