/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:52:49 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/29 12:24:22 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_fork_r(t_philo *philo)
{
	int	taken;
	int	fork_id;

	taken = 0;
	fork_id = (philo->id + philo->input->num_philos - 1)
		% philo->input->num_philos;
	while (!taken)
	{
		pthread_mutex_lock(&philo->input->fork_state[fork_id]);
		if (philo->input->fork_status[fork_id] == 0)
		{
			philo->input->fork_status[fork_id] = 1;
			taken = 1;
		}
		pthread_mutex_unlock(&philo->input->fork_state[fork_id]);
		if (!taken)
			usleep(200);
	}
	print_message(philo, "has taken a fork");
}

void	grab_fork_l(t_philo *philo)
{
	int	taken;
	int	fork_id;

	taken = 0;
	fork_id = philo->id % philo->input->num_philos;
	while (!taken)
	{
		pthread_mutex_lock(&philo->input->fork_state[fork_id]);
		if (philo->input->fork_status[fork_id] == 0)
		{
			philo->input->fork_status[fork_id] = 1;
			taken = 1;
		}
		pthread_mutex_unlock(&philo->input->fork_state[fork_id]);
		if (!taken)
			usleep(200);
	}
	print_message(philo, "has taken a fork");
}

void	drop_fork_r(t_philo *philo)
{
	int	fork_id;

	fork_id = (philo->id + philo->input->num_philos - 1)
		% philo->input->num_philos;
	pthread_mutex_lock(&philo->input->fork_state[fork_id]);
	philo->input->fork_status[fork_id] = 0;
	pthread_mutex_unlock(&philo->input->fork_state[fork_id]);
}

void	drop_fork_l(t_philo *philo)
{
	int	fork_id;

	fork_id = philo->id % philo->input->num_philos;
	pthread_mutex_lock(&philo->input->fork_state[fork_id]);
	philo->input->fork_status[fork_id] = 0;
	pthread_mutex_unlock(&philo->input->fork_state[fork_id]);
}
