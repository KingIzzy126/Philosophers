/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:14:06 by ismailalash       #+#    #+#             */
/*   Updated: 2024/12/27 23:18:05 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_input input;

    if (ac != 5 && ac != 6)
        print_instructions_and_exit();
    if (check(&input, av) != 0)
        return (1);
    // printf("Valid input!\n");
    // printf("Philosophers: %d\n", input.num_philos);
    // printf("Time to die: %d ms\n", input.time_death);
    // printf("Time to eat: %d ms\n", input.time_eat);
    // printf("Time to sleep: %d ms\n", input.time_sleep);
    // printf("Meals (optional): %d\n", input.num_meals);
    return(0);
}