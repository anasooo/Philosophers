/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:27:27 by asodor            #+#    #+#             */
/*   Updated: 2024/12/19 15:05:48 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
    int	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
    write(fd, "\n", 1);
}

unsigned int    ft_atoui(const char *s, bool *error)
{
    unsigned int    res;
    int i;
    
    i = 0;
    res = 0;
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;
    while (s[i] == '+')
        i++;
    if (s[i] == '-' || !s[i])
        return (*error = 1, res);
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + (s[i] - '0');
        if (res > UINT_MAX)
            return (*error = 1, res);
        i++;
    }
    if (s[i] != '\0')
        return (*error = 1, res);    
    return (res);
}

