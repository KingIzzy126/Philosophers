/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:36:17 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/05 11:03:44 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_is_thinking(t_philo *philo)
{
    print_message(philo, "is thinking");
}

void	philosopher_is_sleeping(t_philo *philo)
{
    print_message(philo, "is sleeping");
    precise_sleep(philo->input->time_sleep, philo);
}

void	philosopher_is_eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork.fork);
    print_message(philo, "has taken a fork");
    pthread_mutex_lock(&philo->right_fork.fork);
    print_message(philo, "has taken a fork");
    print_message(philo, "is eating");
    philo->last_meal = get_current_time();
    philo->meals_eaten++;
    precise_sleep(philo->input->time_eat, philo);
    pthread_mutex_unlock(&philo->left_fork.fork);
    pthread_mutex_unlock(&philo->right_fork.fork);
}