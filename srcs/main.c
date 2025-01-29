/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:14:06 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/29 12:29:22 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_input			input;
	pthread_mutex_t	forks[250];

	if (ac != 5 && ac != 6)
		print_instructions_and_exit();
	if (check(&input, av) != 0)
		return (1);
	initialize(&input, forks);
	if (create_threads(&input) != 0)
	{
		clean_up(&input);
		destroy_forks(forks, input.num_philos);
		return (1);
	}
	clean_up(&input);
	destroy_forks(forks, input.num_philos);
	return (0);
}
