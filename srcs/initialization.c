/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:06 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/29 12:27:10 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(pthread_mutex_t *forks, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		pthread_mutex_init(&input->fork_state[i], NULL);
		input->fork_status[i] = 0;
		i++;
	}
}

void	init_philosophers(t_philo *philos, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = input->program_start_time;
		philos[i].input = input;
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
		i++;
	}
}

void	init_program(t_input *input)
{
	pthread_mutex_init(&input->print_mutex, NULL);
	pthread_mutex_init(&input->dead_mutex, NULL);
	input->dead_flag = 0;
	input->program_start_time = get_current_time();
}

void	initialize(t_input *input, pthread_mutex_t *forks)
{
	input->philo = safe_malloc(sizeof(t_philo) * input->num_philos);
	init_program(input);
	init_forks(forks, input);
	init_philosophers(input->philo, input);
}

void	destroy_forks(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
