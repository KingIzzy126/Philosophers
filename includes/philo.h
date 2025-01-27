/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:14:51 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/27 16:48:46 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_input t_input;

typedef struct t_philo
{ 
    int				id;
    int				meals_eaten;
    size_t 			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t meal_mutex;
	pthread_t		thread_id;
	t_input			*input;
}               t_philo;

typedef struct s_input
{
    int				num_philos;
    size_t			time_death;
    size_t			time_eat;
    size_t			time_sleep;
    int			 	num_meals;
	int				dead_flag;
	size_t			program_start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
	t_philo			*philo;
}               t_input;

// parse.c
void	print_instructions_and_exit(void);
int     wrong_input_values(t_input *input);
int     init_args(t_input *input, char **av);
int     is_input_digit(char **av);
int     check(t_input *input, char **av);

// initialization.c
void	init_forks(pthread_mutex_t *forks, int num_philos);
void	init_philosophers(t_philo *philos, t_input *input, pthread_mutex_t *forks);
void	init_program(t_input *input);
void	initialize(t_input *input, pthread_mutex_t *forks);
void	destroy_forks(pthread_mutex_t *forks, int num_philos);

// action.c
void	philosopher_is_thinking(t_philo *philo);
void	philosopher_is_sleeping(t_philo *philo);
void	philosopher_is_eating(t_philo *philo);

// monitor.c
int		check_philo_death(t_input *input);
int 	check_meal_completion(t_input *input);
void	*monitor_routine(void *arg);

// threads.c
int		check_dead_flag(t_philo *philo);
void	*philosopher_actions(void *arguments);
int		join_threads(t_input *input, pthread_t monitor_thread);
int		create_philo_threads(t_input *input);
int		create_monitor_thread(t_input *input, pthread_t *monitor_thread);
int		create_threads(t_input *input);

// utils.c
int     ft_atoi(char *str);
void	*safe_malloc(size_t bytes);
size_t  get_current_time(void);
void    print_message(t_philo *philo, char *str);
int		precise_sleep(size_t time);
void    clean_up(t_input *input);

#endif