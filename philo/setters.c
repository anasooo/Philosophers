/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:55:08 by asodor            #+#    #+#             */
/*   Updated: 2024/12/15 03:01:52 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_ready(t_process *process)
{
    process->ready = true;
}

int set_philo_last_eat(t_philo *philo)
{
    philo->last_eat = ft_get_time();
    return 0;
}