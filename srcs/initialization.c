/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:06 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/23 11:29:27 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_forks(t_philo *philos, int num_philos)
{
    int i;

    i = 0;
    while (i < num_philos)
    {
        pthread_mutex_init(&philos[i].left_fork, NULL);
        pthread_mutex_init(&philos[i].right_fork, NULL);
        i++;
    }
}

void init_philosophers(t_philo *philos, t_input *input)
{
    int i;

    i = 0;
    while (i < input->num_philos)
    {
        philos[i].id = i + 1;
        philos[i].meals_eaten = 0;
        
        philos[i].last_meal = input->program_start_time;
        philos[i].input = input;
        pthread_mutex_init(&philos[i].meal_mutex, NULL);
        if (i == 0)
            philos[i].right_fork = philos[input->num_philos - 1].left_fork; 
        else
            philos[i].right_fork = philos[i - 1].left_fork;
        i++;
    }
}

void init_program(t_input *input)
{
    pthread_mutex_init(&input->print_mutex, NULL);
    pthread_mutex_init(&input->dead_mutex, NULL);
    input->dead_flag = 0;
    input->program_start_time = get_current_time();
}

void initialize(t_input *input)
{
    input->philo = safe_malloc(sizeof(t_philo) * input->num_philos);

    init_program(input);
    init_forks(input->philo, input->num_philos);
    init_philosophers(input->philo, input);
}
