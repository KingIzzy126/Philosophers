/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:25:43 by ialashqa          #+#    #+#             */
/*   Updated: 2025/01/29 12:30:09 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->dead_mutex);
	if (philo->input->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->input->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->input->dead_mutex);
	return (0);
}

int	ft_atoi(char *str)
{
	long long	result;
	int			i;

	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647)
			return (-1);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return ((int)result);
}
