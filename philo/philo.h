/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:47:33 by asodor            #+#    #+#             */
/*   Updated: 2024/12/19 19:42:04 by asodor           ###   ########.fr       */
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

typedef struct s_process t_process;
typedef struct s_philo
{
	int				id;
	t_process		*process;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		thread;
	unsigned int	last_eat;
	int finished;
	pthread_mutex_t	mutex;
}t_philo;

typedef struct s_process
{
	int	number_of_philos;
	t_time			time;
	int				number_of_meals;
	bool			ready;
	bool			philo_died;
	unsigned int	finished;
	t_philo			**philos;
	t_fork			**forks;
	pthread_t		monitor;
	pthread_mutex_t	mutex;
}t_process;


/*==================== utils ===================================*/
int		ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
unsigned int	ft_atoui(const char *s, bool *error);
/*==================== free ====================================*/
void	ft_free_forks(t_fork **forks, long n_philos);
void	ft_free_philos(t_philo **philos, long n_philos);
/*==================== parsing =================================*/
t_process	*ft_parse_input(int ac, char **av);
/*==================== initialization ==========================*/
t_fork		**init_forks(int n_philos);
t_philo		**init_philos(t_process *process, t_fork **forks);
int		ft_initialization(t_process *process, t_fork **forks, t_philo **philos);
/*==================== threads =================================*/
int	ft_threads(t_process *process);
/*==================== routine =================================*/
void	*ft_routine(void *philo);
/*==================== time ====================================*/
unsigned int	ft_get_time(void);
int	ft_usleep(unsigned long time);
/*==================== setters =================================*/
void	set_ready(t_process *process);
void	all_is_ready(t_process *process);
void		set_philo_last_eat(t_philo *philo);
void ft_set_philo_finished(t_philo *philo);
void ft_set_count(t_process *process);
void ft_set_philo_died(t_process *process);
/*==================== check ===================================*/
int ft_check_philo_died(t_process *process);
int ft_check_philo_finished(t_philo *philo);
int ft_check_process_finished(t_process *process);
/*==================== print ===================================*/
void	ft_print_fork(t_philo *philo);
void	ft_print_eating(t_philo *philo);
void	ft_print_sleeping(t_philo *philo);
void	ft_print_thinking(t_philo *philo);
void	ft_print_death(t_philo *philo);
//*==================== forks ==============================*/
int ft_take_forks(t_process *process, t_philo *philo);
int ft_put_forks(t_process *process, t_philo *philo);

//*==================== monitor ==============================*/
void *ft_monitor(void *arg);

#endif