/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:36:17 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/25 14:08:17 by ismailalash      ###   ########.fr       */
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
    precise_sleep(philo->input->time_sleep);
}

void	philosopher_is_eating(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    print_message(philo, "has taken a fork");
    if (philo->input->num_philos == 1)
	{
		precise_sleep(philo->input->time_death);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
    pthread_mutex_lock(philo->left_fork);
    print_message(philo, "has taken a fork");
    pthread_mutex_lock(&philo->meal_mutex);
    philo->eating = 1;
    print_message(philo, "is eating");
    philo->last_meal = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->meal_mutex);
    precise_sleep(philo->input->time_eat);
    pthread_mutex_lock(&philo->meal_mutex);
    philo->eating = 0;
    pthread_mutex_unlock(&philo->meal_mutex);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}
