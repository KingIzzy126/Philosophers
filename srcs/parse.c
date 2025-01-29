/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:37:39 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/29 12:29:30 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_instructions_and_exit(void)
{
	printf("\nWRONG INPUT!\n\n");
	printf("Example:\n");
	printf("./philo 4 800 200 200 5\n\n");
	printf("Num_philos: 1-200\n");
	printf("Time_to_die: 50+\n");
	printf("Time_to_eat: 50+\n");
	printf("Time_to_sleep: 50+\n");
	printf("(optional) Number_of_times_each_philosopher_must_eat: ");
	printf("0+\n");
	exit(1);
}

int	wrong_input_values(t_input *input)
{
	if (input->num_philos < 1 || input->num_philos > 200)
		return (1);
	if (input->time_death < 50 || input->time_eat < 50
		|| input->time_sleep < 50)
		return (1);
	if (input->num_meals < 0 && input->num_meals != -1)
		return (1);
	return (0);
}

int	init_args(t_input *input, char **av)
{
	input->num_philos = ft_atoi(av[1]);
	input->time_death = ft_atoi(av[2]);
	input->time_eat = ft_atoi(av[3]);
	input->time_sleep = ft_atoi(av[4]);
	if (av[5])
		input->num_meals = ft_atoi(av[5]);
	else
		input->num_meals = -1;
	return (0);
}

int	is_input_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("Error: Non-numeric detected in argument%d.\n", i);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check(t_input *input, char **av)
{
	if (is_input_digit(av) != 0)
		print_instructions_and_exit();
	init_args(input, av);
	if (wrong_input_values(input) != 0)
		print_instructions_and_exit();
	return (0);
}
