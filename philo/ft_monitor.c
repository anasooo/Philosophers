/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:42:18 by asodor            #+#    #+#             */
/*   Updated: 2024/12/19 20:19:59 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// int ft_check_last_eat(t_process *process, unsigned int i)
// {
//     bool died;
    
//     pthread_mutex_lock(&process->mutex);
//     // Check if philosopher has exceeded time to die
//     died = (process->time.to_die <= ft_get_time() - process->philos[i]->last_eat);
//     if (died) {
//         ft_set_philo_died(process);
//         // mutex 
//         ft_print_death(process->philos[i]);
//         // mutex 
//         pthread_mutex_unlock(&process->mutex);
//         return (1);
//     }
//     pthread_mutex_unlock(&process->mutex);
        
//     return (0);
// }

// int	ft_is_died(t_process *process)
// {
// 	int	i;
// 	int	died;
// 	int		finished;

// 	i = 0;
// 	died = 0;
// 	while (i < process->number_of_philos && !died)
// 	{
// 		finished = ft_check_philo_finished(process->philos[i]);
// 		if (!finished)
//             died = ft_check_last_eat(process, i);
// 		i++;
// 	}
// 	return (died);
// }

// void	*ft_monitor(void *arg)
// {
//     t_process	*process;
// 	int			check;

// 	process = (t_process *)arg;
//     if (!process)
//         return (NULL);
//     all_is_ready(process);
//     ft_usleep(10);
// 	while (1)
// 	{
// 		if (ft_is_died(process) != 0)
// 			return (NULL);
// 		check = ft_check_process_finished(process);
// 		if (check == process->number_of_philos)
// 			return (NULL);
// 	}
// 	return (NULL);
// }


int	ft_check_last_eat(t_process *p, unsigned int i)
{
	unsigned int	time;
	bool	died;

	died = false;
    pthread_mutex_lock(&p->philos[i]->mutex);
	time = ft_get_time();
	if (p->time.to_die <= time - p->philos[i]->last_eat)
	{
        ft_set_philo_died(p);
		died = true;
		ft_print_death(p->philos[i]);
	}
    pthread_mutex_unlock(&p->philos[i]->mutex);
	return ((int)died);
}

int	ft_is_died(t_process *p)
{
	int	i;
	bool	died;
	int		r;

	i = 0;
	died = false;
	while (i < p->number_of_philos && !died)
	{
		r = ft_check_philo_finished(p->philos[i]);
		if (r == 0)
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
	int			r;

	if (!arg)
		return (NULL);
	p = (t_process *)arg;
    all_is_ready(p);
	ft_usleep(1);
	while (true)
	{
		if (ft_is_died(p) != 0)
			break ;
		r = ft_check_process_finished(p);
		if (r == (int)p->number_of_philos)
			return (NULL);
	}
	return (NULL);
}
