/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:32:13 by asodor            #+#    #+#             */
/*   Updated: 2024/12/15 02:33:09 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	take_r_fork(t_philo *philo, t_process *process)
{   
    if (process->err || process->philo_died)
		return (false);
	ft_print_fork(philo);
	return (true);
}

bool	take_l_fork(t_philo *philo, t_process *process)
{
    if (process->err || process->philo_died)
        return (false);
    ft_print(philo);
    return (true);
}

static bool ft_take_forks(t_process *process, t_philo *philo)
{
    if (philo->id % 2 == 0)
        return (take_r_fork(philo, process) && take_l_fork(philo, process));
    else
        return (take_l_fork(philo, process) && take_r_fork(philo, process));
}