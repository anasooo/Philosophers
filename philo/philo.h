/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:47:33 by asodor            #+#    #+#             */
/*   Updated: 2024/11/28 00:14:36 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdatomic.h>
# include <stdbool.h>


# define EAT "\033[0;32mis eating\n\033[0m"
# define SLEEP "\033[0;34mis sleeping\n\033[0m"
# define THINK "\033[0;33mis thinking\n\033[0m"
# define FORK "has taken a fork\n"
# define DEAD "\033[0;31mdied\n\033[0m"

# define ERROR "Error: Invalid number of arguments. \n<number of philos>\
 <time to die> <time to eat> <time to sleep> [optionel: <number of meals>]\n"


typedef struct s_time
{
	unsigned int 		to_die;
	unsigned int 		to_eat;
	unsigned int 		to_sleep;
}t_time;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}t_fork;

typedef struct s_philo
{
	int				id;
	bool			alive;
	unsigned int			last_meal;
	t_process		*process;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}t_philo;


typedef struct s_process
{
	unsigned int			n_philos;
	t_time					time;
	unsigned int			n_meals;
	bool			ready;
	bool			philo_died;
	bool			err;
	unsigned int			finished;
	t_philo			**philos;
	t_fork			**forks;
	pthread_t		monitor;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print_mutex;
}t_process;


/*==================== init ===================================*/




#endif