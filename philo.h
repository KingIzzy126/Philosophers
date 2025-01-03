/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:14:51 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/03 10:53:50 by ismailalash      ###   ########.fr       */
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

typedef struct s_input
{
    int				num_philos;
    int			 	time_death;
    int			 	time_eat;
    int			 	time_sleep;
    int			 	num_meals;
	int				dead_flag;
	size_t			program_start_time;
	t_fork			*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
	t_philo			*philo;
}               t_input;

typedef struct t_philo
{ 
    int			id;
    int			nbr_meals;
    int			meals_eaten;
    int 		last_meal;
	t_fork		left_fork;
	t_fork		right_fork;
	pthread_t	thread_id;
	t_input		*input;
}               t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}				t_fork;


// parse.c
void	print_instructions_and_exit(void);
int     wrong_input_values(t_input *input);
int     init_args(t_input *input, char **av);
int     is_input_digit(char **av);
int     check(t_input *input, char **av);

// utils.c
int     ft_atoi(char *str);
void	*safe_malloc(size_t bytes);

// initialization.c
int		init_data(t_input *input);
int		init_philo(t_input *input);

#endif