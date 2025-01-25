/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:14:06 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/25 14:47:35 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_input input;
    pthread_mutex_t forks[250];

    if (ac != 5 && ac != 6)
        print_instructions_and_exit();
    if (check(&input, av) != 0)
        return (1);
    initialize(&input, forks);
    create_threads(&input);
    clean_up(&input);
    destroy_forks(forks, input.num_philos);
    return(0);
}