/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:32:13 by asodor            #+#    #+#             */
/*   Updated: 2024/12/17 11:08:57 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_r_fork(t_philo *philo, t_process *process)
{   
    if (process->philo_died)
		return (NULL);
	ft_print_fork(philo);
}

void	take_l_fork(t_philo *philo, t_process *process)
{
    if (process->philo_died)
        return (NULL);
    ft_print_fork(philo);
}

void  ft_take_forks(t_process *process, t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        take_r_fork(philo, process);
        take_l_fork(philo, process);
    }else
    {
        take_l_fork(philo, process);
        take_r_fork(philo, process);
    }
}
