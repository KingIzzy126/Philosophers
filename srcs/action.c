/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:36:17 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/29 11:36:28 by ismailalash      ###   ########.fr       */
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
    grab_fork_r(philo);
    if (philo->input->num_philos == 1)
	{
		precise_sleep(philo->input->time_death);
		drop_fork_r(philo);
		return ;
	}
    grab_fork_l(philo);
    print_message(philo, "has taken a fork");
    pthread_mutex_lock(&philo->meal_mutex);
    print_message(philo, "is eating");
    philo->last_meal = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->meal_mutex);
    precise_sleep(philo->input->time_eat);
    drop_fork_r(philo);
    drop_fork_l(philo);
}
