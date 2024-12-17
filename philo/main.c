/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:22:24 by asodor            #+#    #+#             */
/*   Updated: 2024/12/17 09:46:28 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_process	*process;
	t_fork		**forks;
	t_philo		**philos;
	
	if (ac < 5 || ac > 6)
		return (ft_putendl_fd(ERROR, STDERR_FILENO), 1);
	
	process = ft_parse_input(ac - 1, av + 1);
	if (!process)
		return (ft_putendl_fd(ERROR, STDERR_FILENO), 1);
	ft_initialization(process, forks, philos);
	ft_threads(process);
	ft_free_forks(forks, process->number_of_philos);
	ft_free_philos(philos, process->number_of_philos);
	free(process);	
	return (0);
}