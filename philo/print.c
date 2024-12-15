/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:16:26 by asodor            #+#    #+#             */
/*   Updated: 2024/12/15 03:11:17 by asodor           ###   ########.fr       */
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