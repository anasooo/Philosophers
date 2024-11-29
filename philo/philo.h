/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:47:33 by asodor            #+#    #+#             */
/*   Updated: 2024/11/29 09:38:01 by asodor           ###   ########.fr       */
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
	t_process		*process;
	bool			alive;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}t_philo;


typedef struct s_process
{
	unsigned int			n_philos;
	t_time					*time;
	int			n_meals;
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


/*==================== utils ===================================*/
int		ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
unsigned long	ft_atoul(const char *s, bool *error);
/*==================== free ====================================*/
void	ft_free_forks(t_fork **forks, long n_philos);
void	ft_free_philos(t_philo **philos, long n_philos);
/*==================== parsing =================================*/
t_process	*ft_parse_input(int ac, char **av);
/*==================== initialization ==========================*/
t_fork		**init_forks(int n_philos);
t_philo		**init_philos(t_process *process, t_fork **forks);
void		ft_initialization(t_process *process, t_fork **forks, t_philo **philos);


#endif