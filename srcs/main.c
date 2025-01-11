/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:14:06 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/11 20:56:48 by ismailalash      ###   ########.fr       */
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
    init_data(&input);
    init_philo(&input);
    create_threads(&input);
    clean_up(&input);
    return(0);
}