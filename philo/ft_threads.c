/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 02:08:23 by asodor            #+#    #+#             */
/*   Updated: 2024/12/22 17:59:39 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_process *process)
{
	long	i;

	i = 0;
	while (i < process->number_of_philos)
	{
		if (pthread_create(&process->philos[i]->thread, NULL, ft_routine,
				(void *)process->philos[i]))
			return (ft_putendl_fd("Error: Failed to create thread",
					STDERR_FILENO), 0);
		i++;
	}
	if (pthread_create(&process->monitor, NULL, ft_monitor, (void *)process))
		return (ft_putendl_fd("Error: Failed to create thread", STDERR_FILENO),
			0);
	return (1);
}

int	ft_join_threads(t_process *process)
{
	long	i;

	i = 0;
	while (i < process->number_of_philos)
	{
		if (pthread_join(process->philos[i]->thread, NULL))
			return (ft_putendl_fd("Error: Failed to join thread",
					STDERR_FILENO), 0);
		i++;
	}
	if (pthread_join(process->monitor, NULL))
		return (ft_putendl_fd("Error: Failed to join thread", STDERR_FILENO),
			0);
	return (1);
}

int	ft_threads(t_process *process)
{
	if (!ft_create_threads(process))
		return (0);
	ft_get_time();
	set_ready(process);
	if (!ft_join_threads(process))
		return (0);
	return (1);
}
