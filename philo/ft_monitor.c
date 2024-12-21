/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:42:18 by asodor            #+#    #+#             */
/*   Updated: 2024/12/21 22:57:21 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"        

int	ft_check_last_eat(t_process *p, unsigned int i)
{
	unsigned int	time;
	bool	died;

    pthread_mutex_lock(&p->philos[i]->mutex);
	died = false;
	time = ft_get_time();
	if (p->number_of_philos % 2 == 0)
	{	if (p->time.to_die + 1 < time - p->philos[i]->last_eat )
		{	
     		ft_set_philo_died(p);
			died = true;
			pthread_mutex_lock(&p->mutex1);
			ft_print_death(p->philos[i]);
			pthread_mutex_unlock(&p->mutex1);
		}
	}
	else
		if (p->time.to_die < time - p->philos[i]->last_eat)
		{
			ft_set_philo_died(p);
			died = true;
			pthread_mutex_lock(&p->mutex1);
			ft_print_death(p->philos[i]);
			pthread_mutex_unlock(&p->mutex1);
		}
    pthread_mutex_unlock(&p->philos[i]->mutex);
	return ((int)died);
}

int	ft_is_died(t_process *p)
{
	int	i;
	bool	died;

	i = 0;
	died = false;
	while (i < p->number_of_philos && !died)
	{
		if (ft_check_philo_finished(p->philos[i]) == 0)
		{
			if (ft_check_last_eat(p, i) != 0)
				died = true;
		}
		i++;
	}
	return (died);
}

void	*ft_monitor(void *arg)
{
	t_process	*p;

	if (!arg)
		return (NULL);
	p = (t_process *)arg;
    all_is_ready(p);
	ft_usleep(1);
	while (true)
	{
		if (ft_is_died(p) != 0)
			return (NULL);
		if (ft_check_process_finished(p) == p->number_of_philos)
			return (NULL);
	}
	return (NULL);
}
