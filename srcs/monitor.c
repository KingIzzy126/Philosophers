/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:49:18 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/20 16:09:28 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_philo_death(t_input *input)
{
    int i;
    
    i = 0;
    while(i < input->num_philos)
    {
        pthread_mutex_lock(&input->philo->meal_mutex);
        if (get_current_time() - input->philo->last_meal >= (size_t)input->time_death)
        {
            print_message(&input->philo[i], "died");
            pthread_mutex_lock(&input->dead_mutex);
            input->dead_flag = 1;
            pthread_mutex_unlock(&input->dead_mutex);
            pthread_mutex_unlock(&input->philo->meal_mutex);
            return(1);
        }
        pthread_mutex_unlock(&input->philo->meal_mutex);
        i++;
    }
    return(0);
}

int check_meal_completion(t_input *input)
{
    int i;
    int full_philos;

    full_philos = 0;
    if (input->num_meals <= 0)
        return(0);
    i = 0;
    while (i < input->num_philos)
    {
        pthread_mutex_lock(&input->philo[i].meal_mutex);
        if (input->philo[i].meals_eaten >= input->num_meals)
            full_philos++;
        pthread_mutex_unlock(&input->philo[i].meal_mutex);
        i++;
    }
    if (full_philos == input->num_philos)
    {
        pthread_mutex_lock(&input->dead_mutex);
        input->dead_flag = 1;
        pthread_mutex_unlock(&input->dead_mutex);
        return (1);
    }
    return (0);
}

void *monitor_routine(void *arg)
{
    t_input *input;
    
    input = (t_input *)arg;
    while(!input->dead_flag)
    {
        if (check_philo_death(input) || check_meal_completion(input))
            break;
        usleep(400);
    }
    return (NULL);
}