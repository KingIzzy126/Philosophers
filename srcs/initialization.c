/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:06 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/03 10:46:26 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_data(t_input *input)
{
    int i;
    
    i = 0;
    input->philo = safe_malloc(sizeof(t_philo) * input->num_philos);
    input->forks = safe_malloc(sizeof(t_fork) * input->num_philos);
    while (i <input->num_philos)
    {
        input->forks[i].fork_id = i + 1;
        pthread_mutex_init(&input->forks[i].fork, NULL);
        i++;
    }
    pthread_mutex_init(&input->print_mutex, NULL);
    pthread_mutex_init(&input->dead_mutex, NULL);
    input->dead_flag = 0;
    input->program_start_time = get_current_time();
    return (0);
}

int init_philo(t_input *input)
{
    int i;

    i = 0;
    while (i < input->num_philos)
    {
        input->philo[i].id = i + 1;
        input->philo[i].nbr_meals = input->num_meals;
        input->philo[i].meals_eaten = 0;
        input->philo[i].last_meal = input->program_start_time;
        input->philo[i].input = input;
        input->philo[i].left_fork = input->forks[i];
        input->philo[i].right_fork = input->forks[(i + 1) % input->num_philos];
        i++;
    }
    return (0);
}