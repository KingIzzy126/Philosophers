/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:47:13 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/29 12:25:54 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*buff;

	buff = malloc(bytes);
	if (NULL == buff)
	{
		printf("Error: Memory allocation of %zu bytes failed.\n", bytes);
		return (NULL);
	}
	return (buff);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error: gettimeofday() fail\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(t_philo *philo, char *str)
{
	size_t	time;

	pthread_mutex_lock(&philo->input->print_mutex);
	pthread_mutex_lock(&philo->input->dead_mutex);
	if (philo->input->dead_flag == 0)
	{
		time = get_current_time() - philo->input->program_start_time;
		printf("%zu %d %s\n", time, philo->id, str);
	}
	pthread_mutex_unlock(&philo->input->dead_mutex);
	pthread_mutex_unlock(&philo->input->print_mutex);
}

int	precise_sleep(size_t time)
{
	size_t	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < time)
		usleep(500);
	return (0);
}

void	clean_up(t_input *input)
{
	int	i;

	i = 0;
	if (input->philo != NULL)
	{
		while (i < input->num_philos)
		{
			pthread_mutex_destroy(&input->philo[i].meal_mutex);
			i++;
		}
		free(input->philo);
		input->philo = NULL;
	}
	pthread_mutex_destroy(&input->print_mutex);
	pthread_mutex_destroy(&input->dead_mutex);
}
