/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:32:32 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/29 12:30:17 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_actions(void *arguments)
{
	t_philo	*philo;

	philo = (t_philo *)arguments;
	if (philo->id % 2 == 0)
		precise_sleep(1);
	while (!check_dead_flag(philo))
	{
		philosopher_is_eating(philo);
		philosopher_is_sleeping(philo);
		philosopher_is_thinking(philo);
	}
	return (arguments);
}

int	create_philo_threads(t_input *input)
{
	int	i;

	i = 0;
	while (i < input->num_philos)
	{
		if (pthread_create(&input->philo[i].thread_id, NULL,
				philosopher_actions, &input->philo[i]) != 0)
		{
			printf("Error: Failed to create thread %d\n", i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	create_monitor_thread(t_input *input, pthread_t *monitor_thread)
{
	if (pthread_create(monitor_thread, NULL, monitor_routine, input) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		return (1);
	}
	return (0);
}

int	join_threads(t_input *input, pthread_t monitor_thread)
{
	int	i;

	i = 0;
	while (i < input->num_philos)
	{
		if (pthread_join(input->philo[i].thread_id, NULL) != 0)
		{
			printf("Error: Failed to join threads %d\n", i + 1);
			return (1);
		}
		i++;
	}
	if (pthread_join(monitor_thread, NULL) != 0)
	{
		printf("Error: Failed to join monitor thread\n");
		return (1);
	}
	return (0);
}

int	create_threads(t_input *input)
{
	pthread_t	monitor_thread;

	if (create_philo_threads(input) != 0)
		return (1);
	if (create_monitor_thread(input, &monitor_thread) != 0)
		return (1);
	if (join_threads(input, monitor_thread) != 0)
		return (1);
	return (0);
}
