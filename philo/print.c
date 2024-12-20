/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:16:26 by asodor            #+#    #+#             */
/*   Updated: 2024/12/19 19:38:35 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_print_fork(t_philo *philo)
{
    printf("%u %d %s", ft_get_time(), philo->id, FORK);
}

void    ft_print_eating(t_philo *philo)
{
    printf("%u %d %s", ft_get_time(), philo->id, EAT);
}
void   ft_print_sleeping(t_philo *philo)
{
    printf("%u %d %s", ft_get_time(), philo->id, SLEEP);
}

void    ft_print_thinking(t_philo *philo)
{
    printf("%u %d %s", ft_get_time(), philo->id, THINK);
}

void    ft_print_death(t_philo *philo)
{
    printf("%u %d %s", ft_get_time(), philo->id, DEAD);
}