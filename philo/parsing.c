/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:20:27 by asodor            #+#    #+#             */
/*   Updated: 2024/11/28 05:30:07 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_process *check_n_meals(int ac, t_process *process, char **av)
{
    if (ac == 5)
    {
        process->n_meals = ft_atol(av[4]);
        return (free(process), ft_putendl_fd("Invalid: number of meals\n", STDERR_FILENO), NULL);
    }    
    else
        process->n_meals = -1;
    return (process);
}
t_process	*ft_parse_input(int ac, char **av)
{
    t_process	*process;
    bool       error;
    
    error = 0;
    process = (t_process *)malloc(sizeof(t_process));
    if (!process)
        return (NULL);
    
    process->n_philos = ft_atol(av[0]);
    if(error)
        return (free(process), ft_putendl_fd("Invalid: number of philosophers\n", STDERR_FILENO), NULL);
    process->time->to_die = ft_atol(av[1]);
    if(error)
        return (free(process), ft_putendl_fd("Invalid: time to die\n", STDERR_FILENO), NULL);
    process->time->to_eat = ft_atol(av[2]);
    if(error)
        return (free(process), ft_putendl_fd("Invalid: time to eat\n", STDERR_FILENO), NULL);
    process->time->to_sleep = ft_atol(av[3]);
    if(error)
        return (free(process), ft_putendl_fd("Invalid: time to sleep\n", STDERR_FILENO), NULL);
    return (check_n_meals(ac, process, av));
}

