/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:14:51 by ismailalash       #+#    #+#             */
/*   Updated: 2024/12/27 22:57:55 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_input
{
    int num_philos;
    int time_death;
    int time_eat;
    int time_sleep;
    int num_meals;
}               t_input;

// parse.c
void	print_instructions_and_exit(void);
int     wrong_input_values(t_input *input);
int     init_args(t_input *input, char **av);
int     is_input_digit(char **av);
int     check(t_input *input, char **av);

// utils.c
int     ft_atoi(char *str);

#endif