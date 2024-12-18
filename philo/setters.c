/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:55:08 by asodor            #+#    #+#             */
/*   Updated: 2024/12/18 22:11:57 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_ready(t_process *process)
{
    process->ready = true;
}

void set_philo_last_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex);
    philo->last_eat = ft_get_time();
    pthread_mutex_unlock(&philo->mutex);
}

void ft_set_philo_finished(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex);
    philo->finished = 1;
    pthread_mutex_unlock(&philo->mutex);
}
void ft_update_process_state(t_process *process)
{
    pthread_mutex_lock(&process->mutex);
    process->finished++;
    pthread_mutex_unlock(&process->mutex);
}