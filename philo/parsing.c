/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:20:27 by asodor            #+#    #+#             */
/*   Updated: 2024/11/29 09:37:41 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_process *check_n_meals(int ac, t_process *process, char **av, bool *error)
{
    if (ac == 5)
    {
        process->n_meals = ft_atoul(av[4], error);
        return (free(process), NULL);
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
        return (ft_putendl_fd("Allocation failed!\n", STDERR_FILENO), NULL);
    
    process->n_philos = ft_atoui(av[0], &error);
    if(error)
        return (free(process), NULL);
    process->time->to_die = ft_atoul(av[1], &error);
    if(error)
        return (free(process), NULL);
    process->time->to_eat = ft_atoul(av[2], &error);
    if(error)
        return (free(process), NULL);
    process->time->to_sleep = ft_atoul(av[3], &error);
    if(error)
        return (free(process), NULL);
    return (check_n_meals(ac, process, av, error));
}

