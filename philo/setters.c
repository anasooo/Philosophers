/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:55:08 by asodor            #+#    #+#             */
/*   Updated: 2024/12/17 09:15:09 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_ready(t_process *process)
{
    process->ready = true;
}

void set_philo_last_eat(t_philo *philo)
{
    philo->last_eat = ft_get_time();
}

void ft_set_philo_finished(t_philo *philo)
{
    philo->finished = 1;
}
void ft_update_process_state(t_process *process)
{
    process->finished++;
}